#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 h, n, m;
vector<i64> dirx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<i64> diry = {-1, 0, 1, -1, 1, -1, 0, 1};

i64 bfs(i64 x, i64 y, vector<vector<char>> &v, vector<vector<bool>> &visv) {

  deque<pair<i64, i64>> q;
  i64 res = 0;

  visv[x][y] = true;
  q.push_back({x, y});
  res++;

  while (!q.empty()) {
    auto p = q.front();
    q.pop_front();

    for (i64 k = 0; k < 8; k++) {
      if (p.first % 2) {
        if (k == 0 || k == 5) {
          continue;
        }
      } else {
        if (k == 2 || k == 7) {
          continue;
        }
      }

      i64 xx = p.first + dirx[k];
      i64 yy = p.second + diry[k];

      if (xx >= 0 && yy >= 0 && xx < n && yy < m && v[xx][yy] == '.' &&
          !visv[xx][yy]) {
        q.push_back({xx, yy});
        visv[xx][yy] = true;
        res++;
      }
    }
  }
  return res;
}

int main() {

  cin >> h >> n >> m;

  vector<vector<char>> v(n, vector<char>(m));
  vector<vector<bool>> visv(n, vector<bool>(m));

  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  vector<i64> t;
  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < m; j++) {
      if (v[i][j] == '.' && !visv[i][j]) {
        t.push_back(bfs(i, j, v, visv));
      }
    }
  }

  sort(t.rbegin(), t.rend());

  i64 res = 0;
  if (h == 0) {
    cout << 0 << endl;
    return 0;
  }

  for (auto i : t) {
    h -= i;
    res++;
    if (h <= 0) {
      break;
    }
  }

  cout << res << endl;
  return 0;
}

// nu meie