#include <bits/stdc++.h>

using namespace std;
#define let auto
#define endl '\n'
using i64 = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n, k;
    cin >> n >> k;

    vector<i64> v(5);

    for (i64 i = 0; i < n; i++) {
      i64 a;
      cin >> a;
      v[a % k]++;
    }

    if (v[0] > 0) {
      cout << 0 << endl;
      continue;
    }

    i64 sol = 1000;
    for (int i = 1; i < k; i++) {
      if (v[i] > 0) {
        sol = k - i;
      }
    }

    if (k == 4) {
      if (v[2] >= 2) {
        sol = 0;
      } else {
        if (v[1] >= 2) {
          sol = min(sol, i64(2));
        }
        if (v[1] >= 1 && v[2] == 1) {
          sol = min(sol, i64(1));
        }
      }
    }

    cout << sol << endl;
  }

  return 0;
}