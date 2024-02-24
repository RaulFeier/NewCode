#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using p64 = pair<i64, i64>;
#define vec vector
const i64 INF = 1e9;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  while (true) {
    i64 n, m, q, s;
    cin >> n >> m >> q >> s;

    if (n == 0 and m == 0 and q == 0 and s == 0) {
      break;
    }

    vec<vec<p64>> g(n);

    for (i64 i = 0; i < m; i++) {
      i64 u, v, w;
      cin >> u >> v >> w;

      g[u].push_back({v, w});
    }

    vec<i64> dist(g.size(), INF);
    dist[s] = 0;

    for (i64 i = 0; i < n - 1; i++) {
      bool modified = false;
      for (i64 j = 0; j < n; j++) {
        if (dist[j] != INF) {
          for (auto &c : g[j]) {
            if (dist[j] + c.second >= dist[c.first]) {
              continue;
            }

            dist[c.first] = dist[j] + c.second;
            modified = true;
          }
        }
      }

      if (!modified) {
        break;
      }
    }

    vector<bool> isInCycle(n, false);
    queue<i64> que;

    for (i64 i = 0; i < n; i++) {
      if (dist[i] != INF) {
        for (auto &c : g[i]) {
          if (dist[i] + c.second < dist[c.first]) {
            que.push(c.first);
          }
        }
      }
    }

    while (!que.empty()) {
      i64 crt = que.front();
      que.pop();

      isInCycle[crt] = true;
      for (auto &c : g[crt]) {
        if (!isInCycle[c.first]) {
          que.push(c.first);
        }
      }
    }

    while (q--) {
      i64 query;
      cin >> query;
      if (isInCycle[query]) {
        cout << "-Infinity" << endl;
      } else {
        if (dist[query] == INF) {
          cout << "Impossible" << endl;
        } else {
          cout << dist[query] << endl;
        }
      }
    }
  }

  return 0;
}