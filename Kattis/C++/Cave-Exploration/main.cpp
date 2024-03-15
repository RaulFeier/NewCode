#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using p64 = pair<i64, i64>;

enum { unvisited = -1 };

i64 num_it;

set<p64> bridges;

void bridge(i64 node, vector<vector<i64>> &adj, vector<i64> &low,
            vector<i64> &num, vector<i64> &parents) {
  num[node] = low[node] = num_it++;

  for (auto &next : adj[node]) {
    if (num[next] == unvisited) {
      parents[next] = node;

      bridge(next, adj, low, num, parents);

      if (low[next] > num[node]) {
        if (node > next) {
          bridges.insert({node, next});
        } else {
          bridges.insert({next, node});
        }
      }

      low[node] = min(low[node], low[next]);
    } else if (next != parents[node]) {
      low[node] = min(low[node], num[next]);
    }
  }
}

vector<bool> visited;
i64 cnt;
void dfs(i64 node, vector<vector<i64>> &adj) {
  visited[node] = true;

  cnt++;

  for (auto &next : adj[node]) {
    if (visited[next])
      continue;

    bool bridge = false;

    p64 p;
    if (node > next) {
      p = {node, next};
    } else {
      p = {next, node};
    }

    if (bridges.count(p)) {
      bridge = true;
    }

    if (!bridge)
      dfs(next, adj);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 n, m;
  cin >> n >> m;

  vector<vector<i64>> adj(n);

  for (i64 i = 0; i < m; i++) {
    i64 a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<i64> low(n, 0), num(n, unvisited), parents(n, -1);
  num_it = 0;

  bridge(0, adj, low, num, parents);

  visited.assign(n, false);
  cnt = 0;
  dfs(0, adj);

  cout << cnt << endl;

  return 0;
}