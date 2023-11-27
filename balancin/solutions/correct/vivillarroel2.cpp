// Yapa: solución en O(log n) usando GCD
#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n, c, g;
	cin >> n >> c >> g;
	if (c/gcd(c,g) <= n && g/gcd(c,g) <= n) {
		cout << "SI\n";
	}
	else {
		cout << "NO\n";
	}
	return 0;
}
