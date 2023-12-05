#include <vector>
#include "testlib.h"

using namespace std;

/**
 * Check whether this grid contains a single side-wise connected component. It expects that the grid contains ones and zeros only and that its edges may only contain zeros.
 *
 * **This function mutates its input.**
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

  // TODO: pintar 1s desde (s_i, s_j), sin esto la función siempre retornará false.

  for (int i = 1; i < grid.size() - 1; i++) {
    for (int j = 1; j < grid[i].size() - 1; j++) {
      if (grid[i][j] == 1) {
        return false;
      }
    }
  }
  return true;
}


int main() {
  registerValidation();
  int n = inf.readInt(0, 200'000, "n");
  inf.readSpace();
  int m = inf.readInt(0, 200'000, "m");
  inf.readEoln();
  ensuref(n * m <= 2'000, "%d×%d is greater than 2,000.")

  int n_tokens = 0;
  int n_tiles = 0;
  vector<vector<int>> board(n + 2, vector<int>(m + 2, 0));
  vector<vector<int>> mural(n + 2, vector<int>(m + 2, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int c = inf.readInt(0, 1, "c_{" + i + "," + j + "}");
      n_tokens += c;
      board[i][j] = c;
      if (j != m) {
        inf.readSpace();
      }
    }
    inf.readEoln();
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int c = inf.readInt(0, 1, "c_{" + i + "," + j + "}");
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

  ensure(is_connected(board), "The tokens in the board do not form a connected figure.");
  ensure(is_connected(mural), "The tiles in the mural do not form a connected figure.");

  inf.readEof();
}
