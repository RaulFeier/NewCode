#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 n;
  cin >> n;
  i64 p = 1;

  while (n--) {
    i64 a, b;
    char c;
    cin >> a >> c >> b;

    if (c == '+') {
      i64 d = a + b;
      i64 res = d - p;
      p = res;
      cout << res << endl;
    } else if (c == '-') {
      i64 d = a - b;
      i64 res = d * p;
      p = res;
      cout << res << endl;
    } else if (c == '*') {
      i64 d = a * b;
      i64 res = d * d;
      p = res;
      cout << res << endl;
    } else {
      if (a % 2 == 0) {
        cout << a / 2 << endl;
        p = a / 2;
      } else {
        a += 1;
        cout << a / 2 << endl;
        p = a / 2;
      }
    }
  }

  return 0;
}
