#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 m, d;
    cin >> m >> d;

    vector<i64> v(d);
    for (i64 i = 0; i < d; i++) {
      cin >> v[i];
    }

    i64 ziua = 7;
    i64 cnt = 0;

    for (auto &i : v) {
      for (i64 j = 1; j <= i; j++) {
        if (ziua == 5 and j == 13) {
          cnt++;
        }

        ziua++;
        if (ziua == 8) {
          ziua = 1;
        }
      }
    }

    cout << cnt << '\n';
  }

  return 0;
}