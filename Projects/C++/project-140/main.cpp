#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using p64 = pair<i64, i64>;
using pp64 = pair<i64, p64>;
const i64 INF = 1e18;

i64 dijkstra(vector<vector<p64>> &adj, i64 s, vector<i64> &cost_bikes) {
  vector<vector<i64>> ans(adj.size(), vector<i64>(1001, INF));
  priority_queue<pp64, vector<pp64>, greater<pp64>> pq;

  ans[s][cost_bikes[0]] = 0;
  pq.push({0, {s, cost_bikes[0]}});

  while (!pq.empty()) {
    auto crt = pq.top();
    i64 cost = crt.first;
    i64 city = crt.second.first;
    i64 slownest = crt.second.second;
    pq.pop();

    if (ans[city][slownest] < cost)
      continue;

    if (cost < ans[city][cost_bikes[city]]) {
      ans[city][cost_bikes[city]] = cost;
      pq.push({cost, {city, cost_bikes[city]}});
    }

    for (auto &c : adj[city]) {
      i64 cand = cost + c.second * slownest;
      if (cand < ans[c.first][slownest]) {
        ans[c.first][slownest] = cand;
        pq.push({cand, {c.first, slownest}});
      }
    }
  }

  i64 sol = INF;

  for (int i = 0; i < 1001; i++) {
    sol = min(sol, ans[adj.size() - 1][i]);
  }

  return sol;
}

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n, m;
    cin >> n >> m;

    vector<vector<p64>> adj(n);

    for (i64 i = 0; i < m; i++) {
      i64 u, v, w;
      cin >> u >> v >> w;
      u--;
      v--;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    vector<i64> cost(n);
    for (auto &c : cost) {
      cin >> c;
    }

    cout << dijkstra(adj, 0, cost) << endl;
  }

  return 0;
}