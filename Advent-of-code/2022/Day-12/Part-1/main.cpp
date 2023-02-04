#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using p6 = pair<i64, i64>;

vector<p6> DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

i64 solve(p6 start, p6 stop, vector<vector<char>> &mx) {
  int lin = mx.size();
  int col = mx[0].size();

  vector<vector<i64>> d(lin, vector<i64>(col, 1e9));
  d[start.first][start.second] = 0;
  vector<vector<bool>> visit(lin, vector<bool>(col, false));
  visit[start.first][start.second] = true;
  deque<p6> q;
  q.push_back(start);

  while (!q.empty()) {
    p6 crt = q.front();
    q.pop_front();
    int i = crt.first;
    int j = crt.second;
    for (auto dir : DIRS) {
      int ii = i + dir.first;
      int jj = j + dir.second;
      if (ii >= 0 and jj >= 0 and ii < lin and jj < col and
          mx[ii][jj] - 1 <= mx[i][j] && !visit[ii][jj]) {
        d[ii][jj] = 1 + d[i][j];
        q.push_back({ii, jj});
        visit[ii][jj] = true;
      }
    }
  }
  return d[stop.first][stop.second];
}

int main() {
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};

  vector<vector<char>> m;
  string ans;

  while (cin >> ans) {
    vector<char> vc;
    for (auto &x : ans) {
      vc.push_back(x);
    }
    m.push_back(vc);
  }

  i64 r = m.size();
  i64 c = m[0].size();

  pair<int, int> myself;
  pair<int, int> where;
  for (i64 i = 0; i < r; i++) {
    for (i64 j = 0; j < c; j++) {
      if (m[i][j] == 'S') {
        m[i][j] = 'a';
        myself.first = i;
        myself.second = j;
      }
      if (m[i][j] == 'E') {
        m[i][j] = 'z';
        where.first = i;
        where.second = j;
      }
    }
  }

  cout << solve(myself, where, m) << endl;
  return 0;
}