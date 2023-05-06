#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<i32> vi32;
typedef vector<vi64> vv;
typedef vector<vector<i32>> vv32;
typedef string str;

const vector<int> dirx = {1, -1, 0, 0};
const vector<int> diry = {0, 0, 1, -1};

i32 bfs(vv32 &eep, pair<i64, i64> start, vector<vector<bool>> &visit) {
  deque<pair<i32, i32>> q;
  q.push_back({start.first, start.second});
  i32 crt = 0;

  while (!q.empty()) {
    pair<i32, i32> cur = q.front();
    q.pop_front();

    crt += eep[cur.first][cur.second];
    visit[cur.first][cur.second] = true;

    for (i32 i = 0; i < 4; i++) {
      i32 x = cur.first + dirx[i];
      i32 y = cur.second + diry[i];
      if (x >= 0 and x < eep.size() and y >= 0 and y < eep.front().size() and
          !visit[x][y] and eep[x][y] != 0) {
        q.push_back({x, y});
        visit[x][y] = true;
      }
    }
  }

  return crt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i32 t;
  cin >> t;

  while (t--) {
    i32 l, c;
    cin >> l >> c;

    vv32 v(l, vi32(c));
    for (i64 i = 0; i < l; i++) {
      for (i64 j = 0; j < c; j++) {
        cin >> v[i][j];
      }
    }

    vector<vector<bool>> visit(v.size(), vector<bool>(v.front().size(), false));
    i32 res = 0;
    for (i32 i = 0; i < l; i++) {
      for (i32 j = 0; j < c; j++) {
        if (v[i][j] != 0 && !visit[i][j]) {
          i32 crt = bfs(v, {i, j}, visit);
          res = max(res, crt);
        }
      }
    }

    cout << res << endl;
  }

  return 0;
}

/*
3 3

1 2 0
3 4 0
0 0 5
*/