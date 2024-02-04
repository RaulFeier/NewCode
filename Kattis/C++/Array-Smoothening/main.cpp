#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 n, k;

  cin >> n >> k;
  map<i64, i64> m;

  for (i64 i = 0; i < n; i++) {
    i64 x;
    cin >> x;
    m[x]++;
  }

  vector<i64> v;
  for (auto &c : m) {
    v.push_back(c.second);
  }

  sort(v.rbegin(), v.rend());

  i64 sol = -1;
  for (auto &c : v) {
    if (k == 0) {
      sol = max(sol, c);
      break;
    } else {
      if (c > k) {
        c -= k;
        k = 0;
      } else {
        k -= c;
        c = 0;
      }
    }
    sol = max(sol, c);
  }

  cout << sol << endl;

  return 0;
}

// 5 3 2