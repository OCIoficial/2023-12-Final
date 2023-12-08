#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n; cin >> n;

  set<int> S;

  for(int _ = 0; _ < n/2; ++_) {
    int d; cin >> d;
    int complemento = n+1-d;

    if(S.count(complemento)) {
      cout << "NO\n";
      return 0;
    }

    S.insert(d);
  }

  cout << "SI\n";
  return 0;
}