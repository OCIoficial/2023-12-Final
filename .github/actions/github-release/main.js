const core = require('@actions/core');
const path = require("path");
const fs = require("fs");
const github = require('@actions/github');
const glob = require('glob');

function sleep(milliseconds) {
  return new Promise(resolve => setTimeout(resolve, milliseconds));
}

async function runOnce() {
  // Load all our inputs and env vars. Note that `getInput` reads from `INPUT_*`
  const files = core.getInput('files');
  const name = core.getInput('name');
  const token = core.getInput('token');
  const slug = process.env.GITHUB_REPOSITORY;
  const owner = slug.split('/')[0];
  const repo = slug.split('/')[1];
  const sha = process.env.HEAD_SHA;

  core.info(`files: ${files}`);
  core.info(`name: ${name}`);

  const options = {
    request: {
      timeout: 30000,
    }
  };
  const octokit = github.getOctokit(token, options);

  // Delete the previous release since we can't overwrite one. This may happen
  // due to retrying an upload.
  const releases = await octokit.paginate("GET /repos/:owner/:repo/releases", { owner, repo });
  for (const release of releases) {
    if (release.tag_name !== name) {
      continue;
    }
    const release_id = release.id;
    core.info(`deleting release ${release_id}`);
    await octokit.rest.repos.deleteRelease({ owner, repo, release_id });
  }

  // Creates an official GitHub release for this `tag`
  core.info(`creating a release`);
  const release = await octokit.rest.repos.createRelease({
    owner,
    repo,
    name,
    body: name,
    tag_name: name,
    target_commitish: sha,
    prerelease: false,
  });
  const release_id = release.data.id;

  // Upload all the relevant assets for this release as just general blobs.
  for (const file of glob.sync(files)) {
    const size = fs.statSync(file).size;
    const name = path.basename(file);

    await runWithRetry(async function () {
      // We can't overwrite assets, so remove existing ones from a previous try.
      let assets = await octokit.rest.repos.listReleaseAssets({
        owner,
        repo,
        release_id
      });
      for (const asset of assets.data) {
        if (asset.name === name) {
          core.info(`delete asset ${name}`);
          const asset_id = asset.id;
          await octokit.rest.repos.deleteReleaseAsset({ owner, repo, asset_id });
        }
      }

      core.info(`upload ${file}`);
      const headers = { 'content-length': size, 'content-type': 'application/octet-stream' };
      const data = fs.createReadStream(file);
      await octokit.rest.repos.uploadReleaseAsset({
        data,
        headers,
        name,
        url: release.data.upload_url,
      });
    });
  }
}

async function runWithRetry(f) {
  const retries = 10;
  const maxDelay = 4000;
  let delay = 1000;

  for (let i = 0; i < retries; i++) {
    try {
      await f();
      break;
    } catch (e) {
      if (i === retries - 1)
        throw e;

      core.error(e);
      const currentDelay = Math.round(Math.random() * delay);
      core.info(`sleeping ${currentDelay} ms`);
      await sleep(currentDelay);
      delay = Math.min(delay * 2, maxDelay);
    }
  }
}

async function run() {
  await runWithRetry(runOnce);
}

run().catch(err => {
  core.error(err);
  core.setFailed(err.message);
});
