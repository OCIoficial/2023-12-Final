// @ocimatic should-fail=[st3]

#include <algorithm>
#include <cstdio>

int main() {
  int n, c, g;
  scanf("%d%d%d", &n, &c, &g);
  int gcd = 1;
  for (int i = 2; i <= 100'000'000; ++i) {
    if (g % i == 0 && c % i == 0) {
      gcd = std::max(gcd, i);
    }
  }
  if (c / gcd <= n && g / gcd <= n) {
    printf("SI\n");
  } else {
    printf("NO\n");
  }
}
