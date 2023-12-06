// @ocimatic should-fail=[st3]

#include <algorithm>
#include <cstdio>

int main() {
  int n, c, g;
  scanf("%d%d%d", &n, &c, &g);
  long lcm = 1;
  for (long i = 1; true; ++i) {
    if ((c * i) % g == 0) {
      lcm = c * i;
      break;
    }
  }
  if (lcm / c <= n && lcm / g <= n) {
    printf("SI\n");
  } else {
    printf("NO\n");
  }
}
