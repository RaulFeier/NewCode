#include <bits/stdc++.h>

using namespace std;
using p32 = pair<int, int>;

vector<int> dirx = {0, 0, 0, 1, 2};
vector<int> diry = {0, 0, 0, 2, 1};
const int INF = 1e9;

int bfs(int n, int m) {
  vector<vector<int>> dist(n, vector<int>(m, INF));

  queue<p32> q;
  dist[0][0] = 0;
  q.emplace(0, 0);

  while (!q.empty()) {
    auto crt = q.front();
    q.pop();

    for (int k = 0; k < 5; k++) {
      int xx = crt.first;
      int yy = crt.second;

      if (k == 0) {
        for (int kk = 1; kk <= diry[k]; kk++) {
          if (yy + kk < m)
            if (dist[xx][yy + kk] > dist[crt.first][crt.second] + 1) {
              dist[xx][yy + kk] = dist[crt.first][crt.second] + 1;
              q.emplace(xx, yy + kk);
            }
        }
      } else if (k == 1) {
        for (int kk = 1; kk <= dirx[k]; kk++) {
          if (xx + kk < n)
            if (dist[xx + kk][yy] > dist[crt.first][crt.second] + 1) {
              dist[xx + kk][yy] = dist[crt.first][crt.second] + 1;
              q.emplace(xx + kk, yy);
            }
        }
      } else if (k == 2) {
        for (int kk = 1; kk <= dirx[k]; kk++) {
          if (xx + kk < n and yy + kk < m)
            if (dist[xx + kk][yy + kk] > dist[crt.first][crt.second] + 1) {
              dist[xx + kk][yy + kk] = dist[crt.first][crt.second] + 1;
              q.emplace(xx + kk, yy + kk);
            }
        }
      } else {
        xx = crt.first + dirx[k];
        yy = crt.second + diry[k];

        if (xx >= 0 and xx < n and yy >= 0 and yy < m) {
          if (dist[xx][yy] > dist[crt.first][crt.second] + 1) {
            dist[xx][yy] = dist[crt.first][crt.second] + 1;
            q.emplace(xx, yy);
          }
        }
      }
    }
  }

  return dist[n - 1][m - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ifstream cin{"turcane.in"};
  ofstream cout{"turcane.out"};

  char c;
  cin >> c;

  if (c == '1') {
    int n, m;
    cin >> n >> m;

    int p, q, r;
    cin >> p >> q >> r;
    dirx[1] = q;
    dirx[2] = r;

    diry[0] = p;
    diry[2] = r;

    cout << bfs(n, m) % (INF + 7) << endl;
  } else {
    int n, m;
    cin >> n >> m;

    int p, q, r;
    cin >> p >> q >> r;

    cout << n * m << endl;
  }

  return 0;
}

/*
1
1 10
5 0 0
*/