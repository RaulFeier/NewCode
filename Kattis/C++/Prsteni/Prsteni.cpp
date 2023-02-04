#include <algorithm>
#include <cmath>
#include <iostream>

using namespace ::std;

int main() {
  int n, s, s1, a, b, r;
  cin >> n;
  cin >> s;

  for (int i = 1; i < n; i++) {
    cin >> s1;
    a = s;
    b = s1;

    while (b != 0) {
      r = a % b;
      a = b;
      b = r;
    }
    cout << s / a << "/" << s1 / a << endl;
  }
}
