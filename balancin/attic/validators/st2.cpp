#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int n = inf.readInt(1, 1'000'000, "n");
  inf.readSpace();
  int c = inf.readInt(1, 1'000'000, "c");
  inf.readSpace();
  int g = inf.readInt(1, 1'000'000, "g");
  inf.readEoln();
  inf.readEof();
}
