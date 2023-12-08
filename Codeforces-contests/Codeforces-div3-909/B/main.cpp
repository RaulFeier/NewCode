#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    vector<i64> v(n);

    for (auto &c : v) {
      cin >> c;
    }

    i64 ans = -1;

    for (i64 d = 1; d <= n; d++) {
      if (n % d == 0) {
        i64 mx = -1e18;
        i64 mn = 1e18;
        for (int i = 0; i < n; i += d) {
          i64 t = 0;
          for (int j = i; j < i + d; j++) {
            t += v[j];
          }
          mx = max(mx, t);
          mn = min(mn, t);
        }
        ans = max(ans, mx - mn);
      }
    }

    cout << ans << endl;
  }

  return 0;
}