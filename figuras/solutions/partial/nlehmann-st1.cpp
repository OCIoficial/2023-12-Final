// @ocimatic should-fail=[st2, st3]

#include <algorithm>
#include <cstdio>
#include <tuple>

std::pair<int, int> read(int m) {
  int r = 0, l = m;
  for (int i = 0; i < m; ++i) {
    int v;
    scanf("%d", &v);
    if (v == 1) {
      l = std::min(i, l);
      r = std::max(i, r);
    }
  }
  return {l, r};
}

int main() {
  int n, m, v;

  scanf("%d%d", &n, &m);

  auto board = read(m);
  auto mural = read(m);

  int size = board.second - board.first + 1;
  int d = std::max(mural.first, board.first) -
          std::min(board.second, mural.second) - 1;
  printf("%d\n", d + size);
}
