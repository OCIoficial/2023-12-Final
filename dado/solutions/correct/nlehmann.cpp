#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int n;

  scanf("%d", &n);

  vector<bool> marked(n + 1, false);
  for (int j = 0; j < n / 2; ++j) {
    int i;
    scanf("%d", &i);
    if (marked[i]) {
      printf("NO\n");
      return 0;
    }
    marked[i] = true;
    marked[n + 1 - i] = true;
  }
  printf("SI\n");

  return 0;
}
