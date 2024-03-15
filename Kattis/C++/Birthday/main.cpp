#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

enum { unvisited = -1 };

i64 dfs_number_cnt;
bool bridges(i64 node, vector<vector<i64>> &adj, vector<i64> &dfs_num,
             vector<i64> &dfs_low, vector<i64> &parents) {
  dfs_low[node] = dfs_num[node] = dfs_number_cnt++;

  for (auto &c : adj[node]) {
    if (dfs_num[c] == unvisited) {
      parents[c] = node;
      if (bridges(c, adj, dfs_num, dfs_low, parents)) {
        return true;
      }

      if (dfs_low[c] > dfs_num[node]) {
        return true;
      }

      dfs_low[node] = min(dfs_low[node], dfs_low[c]);
    } else if (c != parents[node]) {
      dfs_low[node] = min(dfs_low[node], dfs_num[c]);
    }
  }

  return false;
}

int main() {
  i64 n, m;

  while (cin >> n >> m) {
    if (n == 0 && m == 0)
      break;

    vector<vector<i64>> adj(n, vector<i64>());

    for (i64 i = 0; i < m; i++) {
      i64 u, v;
      cin >> u >> v;

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs_number_cnt = 0;
    vector<i64> dfs_num(n, unvisited), dfs_low(n, 0), parents(n, -1);
    bool bridge = false;

    for (i64 i = 0; i < n; i++) {
      if (dfs_num[i] == unvisited) {
        if (bridges(i, adj, dfs_num, dfs_low, parents)) {
          bridge = true;
        }
      }
    }

    if (bridge) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}