// @ocimatic should-fail=[st2]
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int n;

  scanf("%d", &n);

  vector<int> vals(n / 2);
  for (int i = 0; i < n / 2; ++i) {
    scanf("%d", &vals[i]);
  }

  for (int i = 0; i < n / 2; ++i) {
    int complement = n + 1 - vals[i];
    for (int j = i + 1; j < n / 2; ++j) {
      if (vals[j] == complement) {
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("SI\n");

  return 0;
}
