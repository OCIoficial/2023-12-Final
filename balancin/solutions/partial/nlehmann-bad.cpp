// @ocimatic should-fail=[st1, st2, st3]

#include <algorithm>
#include <cstdio>

int main() {
  int n, c, g;
  scanf("%d%d%d", &n, &c, &g);

  long gcd = 1;
  for (long i = 1; i * i <= std::max(c, g); ++i) {
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
