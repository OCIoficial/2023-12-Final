// @ocimatic should-fail=[st3]
// Solución a la subtarea 2
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, c, g;
  cin >> n >> c >> g;
  for (int i = 1; i <= n; ++i) {
    long long b = c * i / g;
    if (b <= n && c * i % g == 0) {
      cout << "SI\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
