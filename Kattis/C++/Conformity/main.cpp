#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 n;
  cin >> n;

  map<vector<i64>, i64> m;

  for (i64 i = 0; i < n; i++) {
    vector<i64> line(5);
    for (i64 j = 0; j < 5; j++) {
      cin >> line[j];
    }
    sort(line.begin(), line.end());
    m[line]++;
  }

  i64 mx = 0;
  for (auto comb : m) {
    mx = max(comb.second, mx);
  }

  i64 total = 0;
  for (auto comb : m) {
    if (comb.second == mx)
      total += mx;
  }

  cout << total << endl;

  return 0;
}
