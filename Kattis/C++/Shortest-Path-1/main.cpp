#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const i64 INF = INT64_MAX / 4;
#define endl '\n'

vector<pair<i64, i64>> dij(i64 s, vector<vector<pair<i64, i64>>> &graph) {
  vector<pair<i64, i64>> ans(graph.size(), {INF, -1});
  priority_queue<pair<i64, i64>, vector<pair<i64, i64>>,
                 greater<pair<i64, i64>>>
      pq;

  ans[s] = {0, -1};
  pq.push({0, s});

  while (!pq.empty()) {
    auto crt = pq.top();
    pq.pop();
    i64 dist = crt.first;
    i64 node = crt.second;

    if (dist > ans[node].first) {
      continue;
    }

    for (auto &c : graph[node]) {
      i64 val = crt.first + c.second;
      if (val < ans[c.first].first) {
        ans[c.first] = {val, node};
        pq.push({val, c.first});
      }
    }
  }

  return ans;
}

int main() {
  i64 n, m, q, s;

  while (true) {
    cin >> n >> m >> q >> s;
    if (n == 0 and m == 0 and q == 0 and s == 0) {
      break;
    }

    vector<vector<pair<i64, i64>>> graph(n);

    for (i64 i = 0; i < m; i++) {
      i64 u, v, w;
      cin >> u >> v >> w;
      graph[u].push_back({v, w});
    }

    vector<pair<i64, i64>> dist = dij(s, graph);

    while (q--) {
      i64 eep;
      cin >> eep;

      if (dist[eep].first == INF) {
        cout << "IMPOSSIBLE" << endl;
      } else {
        cout << dist[eep].first << endl;
      }
    }
    cout << endl;
  }

  return 0;
}
