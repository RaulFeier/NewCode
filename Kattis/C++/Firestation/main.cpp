#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using p64 = pair<i64, i64>;

int main() {
  i64 tc;
  cin >> tc;

  vector<i64> fire_station;
  while (tc--) {
    i64 f, m;
    cin >> f >> m;

    for (i64 i = 0; i < f; i++) {
      i64 c;
      cin >> c;

      fire_station.push_back(c);
    }

    vector<vector<p64>> adj(m + 1);
    for (i64 i = 0; i < m; i++) {
      i64 u, v, w;
      cin >> u >> v >> w;

      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
  }

  return 0;
}

/*
1: 10
2: 0
3: 10
4: 20
5: 30
6: 20
*/