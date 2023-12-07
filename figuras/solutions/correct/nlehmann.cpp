#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

template <typename F>
void for_each(int n, int m, F f) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      f(i, j);
    }
  }
}

vector<vector<int>> read_grid(int n, int m) {
  vector<vector<int>> grid(n, vector<int>(m));
  for_each(n, m, [&](int x, int y) { scanf("%d", &grid[x][y]); });
  return grid;
}

template <typename F>
void neighbors(int x, int y, int n, int m, F f) {
  vector<int> dx = {-1, 0, 1, 0};
  vector<int> dy = {0, -1, 0, 1};
  for (int i = 0; i < 4; ++i) {
    int vx = x + dx[i];
    int vy = y + dy[i];
    if (vx >= 0 && vx < n && vy >= 0 && vy < m) {
      f(vx, vy);
    }
  }
}

int bfs(vector<vector<int>>& board, const vector<vector<int>>& mural) {
  int n = board.size();
  int m = board[0].size();

  queue<tuple<int, int, int>> queue;

  // Empezar bfs desde todas las casillas con 1
  for_each(n, m, [&](int x, int y) {
    if (board[x][y]) {
      queue.emplace(x, y, 0);
    }
  });

  int x, y, d;
  while (!queue.empty()) {
    tie(x, y, d) = queue.front();
    queue.pop();

    // Parar cuando llegamos a una casilla con azulejo en el mural
    if (mural[x][y]) {
      return d;
    }

    neighbors(x, y, n, m, [&](int vx, int vy) {
      if (!board[vx][vy]) {
        queue.emplace(vx, vy, d + 1);
        board[vx][vy] = 1;
      }
    });
  }
  return 0;
}

int main() {
  int n, m;

  scanf("%d%d", &n, &m);

  auto board = read_grid(n, m);
  auto mural = read_grid(n, m);

  // Contar la cantidad de unos
  int ones = 0;
  for_each(n, m, [&](int x, int y) { ones += board[x][y]; });

  // Calcular la intersección
  int intersection = 0;
  for_each(n, m,
           [&](int x, int y) { intersection += board[x][y] && mural[x][y]; });

  if (intersection > 0) {
    printf("%d\n", ones - intersection);
  } else {
    int d = bfs(board, mural);
    printf("%d\n", d + ones - 1);
  }

  return 0;
}
