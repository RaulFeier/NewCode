#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using vi64 = vector<i64>;
using p64 = pair<i64, i64>;
using pp64 = pair<i64, p64>;
i64 const INF = 1e9;

i64 dijkstra(vector<vector<p64>> &adj, i64 s, vi64 &prices, i64 end,
             i64 capacity) {
  vector<vector<i64>> ans(adj.size() + 1, vector<i64>(101, INF));
  priority_queue<pp64, vector<pp64>, greater<pp64>> pq;

  pq.push({0, {s, 0}});
  ans[s][0] = 0;

  while (!pq.empty()) {
    auto crt = pq.top();
    i64 cost = crt.first;
    i64 city = crt.second.first;
    i64 fuel = crt.second.second;
    pq.pop();

    if (city == end) {
      break;
    }

    if (cost > ans[city][fuel]) {
      continue;
    }

    if (fuel < capacity) {
      if (cost + prices[city] < ans[city][fuel + 1]) {
        ans[city][fuel + 1] = cost + prices[city];
        pq.push({ans[city][fuel + 1], {city, fuel + 1}});
      }
    }

    for (auto &c : adj[city]) {
      i64 gas_left = fuel - c.second;
      if (gas_left >= 0 and cost < ans[c.first][gas_left]) {
        ans[c.first][gas_left] = cost;
        pq.push({cost, {c.first, gas_left}});
      }
    }
  }

  i64 sol = INF;
  for (int i = 0; i <= capacity; i++) {
    sol = min(sol, ans[end][i]);
  }

  return sol;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 n, m;
  cin >> n >> m;

  vi64 prices(n);
  for (auto &c : prices) {
    cin >> c;
  }

  vector<vector<p64>> adj(n, vector<p64>());

  for (i64 i = 0; i < m; i++) {
    i64 u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  i64 q;
  cin >> q;
  while (q--) {
    i64 capacity, start, end;
    cin >> capacity >> start >> end;

    auto ans = dijkstra(adj, start, prices, end, capacity);

    if (ans >= INF) {
      cout << "impossible" << endl;
    } else {
      cout << ans << endl;
    }
  }

  return 0;
}