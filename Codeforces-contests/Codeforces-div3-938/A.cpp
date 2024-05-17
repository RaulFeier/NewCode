#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 a, b, n;
    cin >> n >> a >> b;

    if (a * 2 < b) {
      cout << a * n << endl;
    } else {
      if (n % 2 == 0) {
        cout << b * (n / 2) << endl;
      } else {
        cout << b * (n / 2) + a << endl;
      }
    }
  }

  return 0;
}