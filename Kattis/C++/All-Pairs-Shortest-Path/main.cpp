#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  while (true) {
    i64 n, m, q;
    cin >> n >> m >> q;

    if (n == 0 and m == 0 and q == 0) {
      break;
    }

    vector<vector<i64>> g(n, vector<i64>(n, 1e9));

    for (i64 i = 0; i < n; i++) {
      g[i][i] = 0;
    }

    for (i64 i = 0; i < m; i++) {
      i64 u, v, w;
      cin >> u >> v >> w;

      g[u][v] = min(g[u][v], w);
    }

    for (i64 k = 0; k < n; k++) {
      for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < n; j++) {
          if (g[i][j] > g[i][k] + g[k][j] && g[i][k] < 1e9 && g[k][j] < 1e9) {
            g[i][j] = g[i][k] + g[k][j];
          }
        }
      }
    }

    for (i64 i = 0; i < n; i++) {
      for (i64 j = 0; j < n; j++) {
        for (i64 k = 0; k < n; k++) {
          if (g[k][k] < 0 and g[i][k] != 1e9 and g[k][j] != 1e9) {
            g[i][j] = -1e9;
          }
        }
      }
    }

    while (q--) {
      i64 u, w;
      cin >> u >> w;

      if (g[u][w] == 1e9) {
        cout << "Impossible" << '\n';
      } else if (g[u][w] == -1e9) {
        cout << "-Infinity" << '\n';
      } else {
        cout << g[u][w] << '\n';
      }
    }

    cout << '\n';
  }

  return 0;
}