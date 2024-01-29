#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
  i64 n, f, a, b;
  cin >> n >> f >> a >> b;

  vector<i64> m(n);
  for (auto &c : m) {
    cin >> c;
  }

  i64 usage = min(a, b);

  sort(m.begin(), m.end());

  i64 start = 0;
  bool ok = false;
  for (i64 i = 0; i < n; i++) {
    f -= ((m[i] - start) * usage);
    if (f <= 0) {
      ok = true;
      break;
    }
  }

  if (ok) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}