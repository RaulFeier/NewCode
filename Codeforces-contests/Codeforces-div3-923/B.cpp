#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n, m, k;

    cin >> n >> m >> k;

    set<i64> m1;
    for (i64 i = 0; i < n; i++) {
      i64 a;
      cin >> a;
      m1.insert(a);
    }

    set<i64> m2;
    for (i64 i = 0; i < m; i++) {
      i64 a;
      cin >> a;
      m2.insert(a);
    }

    i64 m1_count = k / 2;
    i64 m2_count = k / 2;
    bool we_can = true;
    for (i64 i = 1; i <= k; i++) {
      if (m1.count(i) and m2.count(i)) {
        if (m1_count > m2_count) {
          m1_count--;
        } else {
          m2_count--;
        }
        continue;
      }

      if (m1.count(i) and !m2.count(i) and m1_count > 0) {
        m1_count--;
      } else if (!m1.count(i) and m2.count(i) and m2_count > 0) {
        m2_count--;
      } else {
        we_can = false;
        break;
      }
    }

    if (we_can) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}