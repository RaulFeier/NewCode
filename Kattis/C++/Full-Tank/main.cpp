#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using vi64 = vector<i64>;
using p64 = pair<i64, i64>;

int main() {
  i64 n, m;
  cin >> n >> m;

  vi64 prices(n);
  for (auto &c : prices) {
    cin >> c;
  }

  vector<vector<p64>> g(n, vector<p64>());

  for (i64 i = 0; i < n; i++) {
    i64 a, b, d;
    cin >> a >> b >> d;
    g[a].push_back({b, d});
  }

  i64 q;
  cin >> q;
  while (q--) {
    i64 capacity, start, end;
    cin >> capacity >> start >> end;
  }

  return 0;
}