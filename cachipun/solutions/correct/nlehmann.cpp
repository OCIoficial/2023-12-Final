#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> table = {
    // R  P  S
    {0, 1, -1}, // R
    {-1, 0, 1}, // P
    {1, -1, 0}  // S
};

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> score(n, 0);
  while (k--) {
    vector<int> count(3, 0), plays(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &plays[i]);
      ++count[plays[i]];
    }
    for (int i = 0; i < n; ++i) {
      int v = plays[i];
      score[i] += table[0][v] * count[0];
      score[i] += table[1][v] * count[1];
      score[i] += table[2][v] * count[2];
    }
  }

  for (int i = 0; i < n; ++i) {
    printf("%d ", score[i]);
  }
  printf("\n");
}
