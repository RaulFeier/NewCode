#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> adj[i][j];
      }
    }

    vector<vector<int>> dist(n, vector<int>(m, 0));

    dist[0][0] = adj[0][0];
    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
      auto crt = q.front();
      q.pop();

      pair<int, int> pos_right = {crt.first, crt.second + 1};
      pair<int, int> pos_down = {crt.first + 1, crt.second};

      if (pos_right.second < m) {
        int cand = __gcd(dist[crt.first][crt.second],
                         adj[pos_right.first][pos_right.second]);

        if (cand > dist[pos_right.first][pos_right.second]) {
          dist[pos_right.first][pos_right.second] = cand;
          q.push(pos_right);
        }
      }

      if (pos_down.first < n) {
        int cand = __gcd(dist[crt.first][crt.second],
                         adj[pos_down.first][pos_down.second]);

        if (cand > dist[pos_down.first][pos_down.second]) {
          dist[pos_down.first][pos_down.second] = cand;
          q.push(pos_down);
        }
      }
    }

    cout << dist[n - 1][m - 1] << endl;
  }

  return 0;
}
