#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  cin.tie(0);
  cout.tie(0);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    i64 total = 0;
    for (i64 i = 0; i < n; i++) {
      i64 a;
      cin >> a;

      total += (a % n);
    }

    if (total % n == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}