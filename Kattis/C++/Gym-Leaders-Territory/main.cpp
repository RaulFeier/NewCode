#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

enum { unvisited = -1 };

int n, k, m;
vector<int> dfs_num, dfs_low, parent;
int cnt;
int k_degree;

void dfs(int node, vector<vector<int>> &adj) {
  dfs_num[node] = dfs_low[node] = cnt++;

  for (auto &c : adj[node]) {
    if (dfs_num[c] == unvisited) {
      parent[c] = node;
      dfs(c, adj);

      if (dfs_low[c] > dfs_low[node]) {
        if (c == k - 1 or node == k - 1) {
          k_degree--;
        }
      }

      dfs_low[node] = min(dfs_low[node], dfs_low[c]);
    } else if (c != parent[node]) {
      dfs_low[node] = min(dfs_low[c], dfs_num[node]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k >> m;

  vector<vector<int>> adj(n);
  k_degree = 0;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    if (u == k - 1 or v == k - 1) {
      k_degree++;
    }
  }

  dfs_num.assign(n, unvisited);
  dfs_low.assign(n, 0);
  parent.assign(n, -1);
  cnt = 0;

  dfs(k - 1, adj);

  if (k_degree == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}