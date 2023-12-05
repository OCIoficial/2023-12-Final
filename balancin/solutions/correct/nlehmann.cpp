#include <cstdio>
#include <numeric>

int main() {
  int n, c, g;

  scanf("%d%d%d", &n, &c, &g);

  int m = std::gcd(c, g);

  if (c / m <= n && g / m <= n) {
    printf("SI\n");
  } else {
    printf("NO\n");
  }
}
