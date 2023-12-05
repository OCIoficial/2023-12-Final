#include <queue>
#include <set>
#include <utility>
#include <vector>
#include "testlib.h"

using namespace std;

const vector<pair<int, int>> DIRECTIONS {
    {+1, +0},
    {+0, +1},
    {+0, -1},
    {-1, +0},
};


/**
 * Check whether this grid contains a single side-wise connected component of ones.
 * It asumes that the grid contains ones and zeros only and that its edges may only contain zeros.
 *
 * @param grid The grid to check.
 * @return true if there is exactly one component, false otherwise.
 */
bool is_connected(vector<vector<int>> grid) {
  // Get starting point
  int s_i = 0;
  int s_j = 0;
  for (int i = 1; i < grid.size() - 1; i++) {
    for (int j = 1; j < grid[i].size() - 1; j++) {
      if (grid[i][j] == 1) {
        s_i = i;
        s_j = j;
        break;
      }
    }
    if (s_i > 0) break;
  }
  if (s_i == 0) return false;

  queue<pair<int, int>> unvisited;
  set<pair<int, int>> marked;

  marked.insert(pair<int, int>(s_i, s_j));
  unvisited.push(pair<int, int>(s_i, s_j));
  while (!unvisited.empty()) {
    pair<int, int> visiting = unvisited.front();
    unvisited.pop();
    for (auto d: DIRECTIONS) {
      pair<int, int> n{visiting.first + d.first, visiting.second + d.second};

      if (grid[n.first][n.second] == 0 || marked.find(n) != marked.end()) {
        continue;
      }

      marked.insert(n);
      unvisited.push(n);
    }
  }

  // Check all ones belong to the connected component.
  int count = 0;
  for (int i = 1; i < grid.size() - 1; i++) {
    for (int j = 1; j < grid[i].size() - 1; j++) {
      count += grid[i][j];
    }
  }
  return count == marked.size();
}


int main() {
  registerValidation();
  int n = inf.readInt(1, 1, "n");
  inf.readSpace();
  int m = inf.readInt(0, 2'000, "m");
  inf.readEoln();

  int n_tokens = 0;
  int n_tiles = 0;
  vector<vector<int>> board(n + 2, vector<int>(m + 2, 0));
  vector<vector<int>> mural(n + 2, vector<int>(m + 2, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int b = inf.readInt(0, 1, "b_{" + to_string(i) + "," + to_string(j) + "}");
      n_tokens += b;
      board[i][j] = b;
      if (j != m) {
        inf.readSpace();
      }
    }
    inf.readEoln();
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int c = inf.readInt(0, 1, "c_{" + to_string(i) + "," + to_string(j) + "}");
      n_tiles += c;
      mural[i][j] = c;
      if (j != m) {
        inf.readSpace();
      }
    }
    inf.readEoln();
  }

  ensuref(
    n_tokens == n_tiles,
    "The number of tokens (%d) and tiles (%d) are not the same.",
    n_tokens,
    n_tiles
  );

  ensuref(is_connected(board), "The tokens in the board do not form a connected figure.");
  ensuref(is_connected(mural), "The tiles in the mural do not form a connected figure.");

  inf.readEof();
}
