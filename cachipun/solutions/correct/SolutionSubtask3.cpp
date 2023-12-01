#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> puntaje(n, 0);
  while (k--) {
    vector<int> jugadas(n), cuenta(3, 0);
    for (int i = 0; i < n; ++i) {
      cin >> jugadas[i];
      ++cuenta[jugadas[i]];
    }

    for (int i = 0; i < n; ++i) {
      int j = jugadas[i];
      puntaje[i] += cuenta[(j + 2) % 3] - cuenta[(j + 1) % 3];
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << puntaje[i] << ' ';
  }
  cout << '\n';

  return 0;
}
