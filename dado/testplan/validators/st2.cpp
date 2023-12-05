#include <map>
#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int n = inf.readInt(2, 1'000'000, "n");
  ensuref(n % 2 == 0, "%d is not an even number.");
  inf.readEoln();

  map<int, int> values_with_index;
  for (int i = 1; i <= n / 2; i++) {
    int d = inf.readInt(1, n, "d_{" + to_string(i) + "}");
    ensuref(
      values_with_index.find(d) == values_with_index.end(),
      "%d appeared twice (%d° and %d° values).",
      d,
      values_with_index[d],
      i
    );
    values_with_index[d] = i;
    if (i != n) {
      inf.readSpace();
    }
  }
  inf.readEoln();
  inf.readEof();
}
