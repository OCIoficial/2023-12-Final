#include "testlib.h"
#include <map>

using namespace std;

int main() {
  registerValidation();
  int n = inf.readInt(2, 1'000'000, "n");
  ensuref(n % 2 == 0, "%d is not an even number.");
  inf.readEoln();

  map<int, int> values_with_index;
  for (int i = 1; i <= n / 2; i++) {
    if (i > 1) {
      inf.readSpace();
    }
    int d = inf.readInt(1, n, "d_{" + to_string(i) + "}");
    ensuref(!values_with_index.count(d),
            "%d appeared twice (%d° and %d° values).", d,
            *values_with_index.find(d), i);
    values_with_index[d] = i;
  }
  inf.readEoln();
  inf.readEof();
}
