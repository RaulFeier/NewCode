#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using p64 = pair<long, long>;
const i64 INF = 1e9;

const vector<i64> dirx = {2, 2, -2, -2, 1, 1, -1, -1};
const vector<i64> diry = {1, -1, 1, -1, 2, -2, 2, -2};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 r, c;
  p64 g;
  p64 l;

  while (cin >> r >> c >> g.first >> g.second >> l.first >> l.second) {
    vector<vector<i64>> adj(r + 1, vector<i64>(c + 1, INF));

    adj[g.first][g.second] = 0;

    queue<p64> q;
    q.push({g.first, g.second});

    while (!q.empty()) {
      auto crt = q.front();
      q.pop();

      for (i64 i = 0; i < 8; i++) {
        i64 xx = crt.first + dirx[i];
        i64 yy = crt.second + diry[i];

        if (xx < 1 || xx > r || yy < 1 || yy > c)
          continue;

        if (adj[xx][yy] > adj[crt.first][crt.second] + 1) {
          adj[xx][yy] = adj[crt.first][crt.second] + 1;
          q.push({xx, yy});
        }
      }
    }

    if (adj[l.first][l.second] == INF) {
      cout << "impossible" << endl;
    } else {
      cout << adj[l.first][l.second] << endl;
    }
  }

  return 0;
}