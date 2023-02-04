#include <cmath>
#include <iostream>

using namespace ::std;

int main() {
  int p, q, s, zes, a, b;
  cin >> p >> q >> s;
  a = p;
  b = q;

  while (q != 0) {
    zes = p % q;
    p = q;
    q = zes;
  }

  if ((a / p) * b <= s) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}
