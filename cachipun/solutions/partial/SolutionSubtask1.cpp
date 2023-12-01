// @ocimatic should-pass=[st1]
// Ojala acepte eso uf
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  if (n > 2) {
    cout << "Chao nose\n";
    return 0;
  }

  vector<int> puntaje(2, 0);
  for (int i = 0; i < k; ++i) {
    int jugada0, jugada1;
    cin >> jugada0 >> jugada1;

    int delta = jugada0 - jugada1;
    if (delta == -2)
      delta = 1;
    if (delta == 2)
      delta = -1;

    puntaje[0] += delta;
    puntaje[1] -= delta;
  }

  cout << puntaje[0] << ' ' << puntaje[1] << '\n';
  return 0;
}
