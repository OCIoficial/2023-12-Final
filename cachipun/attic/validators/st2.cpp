#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int n = inf.readInt(2, 100, "n");
  inf.readSpace();
  int k = inf.readInt(1, 3'000, "k");
  inf.readEoln();

  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      int d = inf.readInt(0, 2, "d_{" + to_string(i) + "," + to_string(j) + "}");
      if (j != n) {
        inf.readSpace();
      }
    }
    inf.readEoln();
  }
  inf.readEof();
}
