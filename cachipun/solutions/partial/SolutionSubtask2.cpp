// @ocimatic should-pass=[st2]
// Ojala acepte eso uf
#include <iostream>
#include <vector>

int main() {
	int n, k; 
	cin >> n >> k;

	vector<int> puntaje(n, 0);
	while(k--) {
		vector<int> jugadas(n);
		for(int i = 0; i < n; ++i) cin >> jugadas[i];

		for(int i = 0; i < n; ++i) {
			for(int j = i+1; j < n; ++j) {
				int delta = jugadas[i] - jugadas[j];
				if(delta == -2) delta = 1;
				if(delta == 2) delta = -1;

				puntaje[i] += delta;
				puntaje[j] -= delta;
			}
		}
	}

	for(int i = 0; i < n; ++i) cout << puntaje[i] << ' ';
	cout << '\n';

	return 0;
}