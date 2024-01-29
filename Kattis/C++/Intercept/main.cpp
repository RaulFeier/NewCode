#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void dij(vector<vector<pair<i64, i64>>> &g, vector<i64> &dist, i64 s) {
  dist.assign(g.size(), 1e18);
  priority_queue<pair<i64, i64>, vector<pair<i64, i64>>,
                 greater<pair<i64, i64>>>
      pq;

  dist[s] = 0;
  pq.push({0, s});

  while (!pq.empty()) {
    auto crt = pq.top();
    pq.pop();

    if (crt.first > dist[crt.second]) {
      continue;
    }

    for (auto &c : g[crt.second]) {
      auto cand = crt.first + c.second;
      if (cand < dist[c.first]) {
        dist[c.first] = cand;
        pq.push({cand, c.first});
      }
    }
  }
}

int main() {
  i64 n, m;
  cin >> n >> m;

  vector<vector<pair<i64, i64>>> e(n);
  vector<vector<pair<i64, i64>>> vv(n);

  for (i64 i = 0; i < m; i++) {
    i64 u, v, w;
    cin >> u >> v >> w;

    e[u].push_back({v, w});
    vv[v].push_back({u, w});
  }

  vector<i64> dist;
  vector<i64> distr;

  i64 s, t;
  cin >> s >> t;

  dij(e, dist, s);
  dij(vv, distr, t);

  vector<bool> visit(n, false);
  visit[s] = true;
  priority_queue<pair<i64, i64>, vector<pair<i64, i64>>,
                 greater<pair<i64, i64>>>
      pq;

  pq.push({0, s});

  vector<i64> ans;

  while (!pq.empty()) {
    auto crt = pq.top().second;
    pq.pop();

    if (pq.empty()) {
      ans.push_back(crt);
    }

    for (auto &c : e[crt]) {
      i64 node = c.first;
      i64 distt = c.second;

      if (visit[node]) {
        continue;
      }
      if (dist[t] == dist[crt] + distt + distr[node]) {
        pq.push({dist[node], node});
        visit[node] = true;
      }
    }
  }

  sort(ans.begin(), ans.end());

  for (auto &c : ans) {
    cout << c << " ";
  }
  cout << endl;

  return 0;
}