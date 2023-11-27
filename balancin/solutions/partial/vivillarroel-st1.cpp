// @ocimatic should-pass=[st1]
// Solución a la subtarea 1
#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, c, g;
	cin >> n >> c >> g;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <=n; ++j) {
			if (c*i == g*j) {
				cout << "SI\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}
