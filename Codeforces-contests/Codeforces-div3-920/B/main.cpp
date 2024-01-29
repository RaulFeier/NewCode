#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    string s, f;
    cin >> s >> f;

    i64 x = 0, y = 0;
    for (i64 i = 0; i < n; i++) {
      if (s[i] == f[i]) {
        continue;
      }

      if (s[i] == '1') {
        x++;
      }

      if (f[i] == '1') {
        y++;
      }
    }

    cout << max(x, y) << endl;
  }

  return 0;
}