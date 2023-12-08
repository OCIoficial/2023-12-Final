#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 1e7;

int DI[] = {-1, 1, 0, 0},
    DJ[] = {0, 0, -1, 1};

bool valid(int i, int j, int n, int m) {
  return i >= 0 && j >= 0 && i < n && j < m;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, m; cin >> n >> m;

  vector<vector<int>> T[2];

  for(int k = 0; k < 2; ++k) {
    T[k].assign(n, vector<int>(m));

    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j)
        cin >> T[k][i][j];
  }

  bool intersect = false;
  int diff = 0;

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if(T[0][i][j] && T[1][i][j]) intersect = true;
      if((T[0][i][j] ^ T[1][i][j]) == 1) ++diff;
    }
  }

  diff /= 2;

  if(intersect) {
    cout << diff << '\n';
    return 0;
  }

  queue<pii> Q;
  vector<vector<int>> D(n, vector<int>(m, INF));

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      if(T[0][i][j]) {
        Q.emplace(i, j);
        D[i][j] = 0;
      }
    }
  }

  int dist = -1;
  while(!Q.empty()) {
    pii p = Q.front(); Q.pop();
    int i = p.first, j = p.second;

    if(T[1][i][j]) {
      dist = D[i][j];
      break;
    }

    for(int k = 0; k < 4; ++k) {
      int ii = i + DI[k], jj = j + DJ[k];

      if(valid(ii, jj, n, m) && D[ii][jj] > D[i][j] + 1) {
        D[ii][jj] = D[i][j] + 1;
        Q.emplace(ii, jj);
      }
    }
  }

  cout << dist + diff - 1 << '\n';
  return 0;
}