#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 n;
  cin >> n;

  for (i64 i = 0; i < n; i++) {
    i64 b;
    double p;
    cin >> b >> p;

    double ans = 60.0 * (b / p);
    double t = 60 / p;

    cout << fixed;
    cout.precision(4);
    cout << ans - t << " " << ans << " " << ans + t << endl;
  }

  return 0;
}