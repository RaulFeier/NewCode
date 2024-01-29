#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using p64 = pair<i64, i64>;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    vector<p64> v(4);

    for (auto &c : v) {
      cin >> c.first >> c.second;
    }

    sort(v.begin(), v.end());

    cout << abs(v[0].first - v[3].first) * abs(v[0].second - v[3].second)
         << endl;
  }

  return 0;
}