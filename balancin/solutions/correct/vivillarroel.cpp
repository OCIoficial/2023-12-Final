#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, c, g;
	cin >> n >> c >> g;
	long long gcd = 1;
	if (c > g) swap(c,g);
	for (long long i = 1; i*i <= c; ++i) {
		if (c % i == 0) {
			if (g % i == 0) {
				gcd = max(i, gcd);
			}
			if (g % (c/i) == 0) {
				gcd = max(c/i, gcd);
			}
		}
	}
	if (c/gcd <= n && g/gcd <= n){
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}
	return 0;
}
