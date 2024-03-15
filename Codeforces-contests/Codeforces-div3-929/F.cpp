#include <bits/stdc++.h>

using namespace std;
using p32 = pair<int, int>;
const int INF = 1e9;
#define endl "\n"

const vector<int> dirx = {1, -1, 0, 0};
const vector<int> diry = {0, 0, 1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tc;
  cin >> tc;

  while (tc--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> times(n, vector<int>(m, INF));

    queue<p32> rocks_start;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> v[i][j];

        if (v[i][j] == 1) {
          rocks_start.emplace(i, j);
          times[i][j] = 0;
        }
      }
    }

    while (!rocks_start.empty()) {
      auto crt = rocks_start.front();
      rocks_start.pop();

      for (int i = 0; i < 4; i++) {
        int xx = crt.first + dirx[i];
        int yy = crt.second + diry[i];

        if (xx >= 0 and yy >= 0 and xx < n and yy < m) {
          if (v[xx][yy] == 0 and
              times[xx][yy] > times[crt.first][crt.second] + 1) {
            times[xx][yy] = times[crt.first][crt.second] + 1;
            rocks_start.emplace(xx, yy);
          }
        }
      }
    }
  }
  return 0;
}