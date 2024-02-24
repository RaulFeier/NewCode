#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using p64 = pair<i64, i64>;
using pp64 = pair<i64, p64>;
const i64 INF = 1e9;
#define vec vector
#define ft first
#define sd second

const i64 dirx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
const i64 diry[8] = {1, 0, -1, 1, 0, -1, 1, -1};

pair<i64, set<p64>> dij(i64 s, vec<vec<i64>> &bl) {
  map<p64, p64> m;
  vec<vec<i64>> ans(bl.size(), vec<i64>(bl.front().size(), INF));
  priority_queue<pp64, vec<pp64>, greater<pp64>> pq;

  ans[0][s] = bl[0][s];
  pq.push({bl[0][s], {0, s}});
  m[{0, s}] = {-1, -1};

  while (!pq.empty()) {
    auto crt = pq.top();
    pq.pop();

    auto node = crt.second;
    auto dist = crt.first;

    if (dist != ans[node.ft][node.sd]) {
      continue;
    }

    for (int i = 0; i < 8; i++) {
      i64 x = node.ft + dirx[i];
      i64 y = node.sd + diry[i];

      if (x >= 0 && x < bl.size() && y >= 0 && y < bl.front().size()) {
        i64 cand = dist + bl[x][y];
        if (cand < ans[x][y]) {
          ans[x][y] = cand;
          pq.push({cand, {x, y}});
          m[{x, y}] = node;
        }
      }
    }
  }

  i64 sol = INF;
  p64 crt;

  for (i64 i = 0; i < ans.front().size(); i++) {
    if (ans[bl.size() - 1][i] < sol) {
      sol = ans[bl.size() - 1][i];
      crt = {bl.size() - 1, i};
    }
  }

  set<p64> sol_s;

  while (crt.first != -1) {
    sol_s.insert(crt);
    crt = m[crt];
  }

  return {sol, sol_s};
}

int main() {
  i64 n, m;

  while (true) {
    cin >> n >> m;

    if (n == 0 && m == 0) {
      break;
    }

    vec<vec<i64>> bl(n, vector<i64>(m));

    for (i64 i = 0; i < n; i++) {
      for (i64 j = 0; j < m; j++) {
        char c;
        cin >> c;
        bl[i][j] = c - '0';
      }
    }

    i64 sol = INF;
    set<p64> s;
    for (i64 i = 0; i < m; i++) {
      auto p = dij(i, bl);
      if (sol > p.first) {
        sol = p.first;
        s = p.second;
      }
    }

    for (i64 i = 0; i < n; i++) {
      for (i64 j = 0; j < m; j++) {
        if (s.count({i, j}) == 0) {
          cout << bl[i][j];
        } else {
          cout << " ";
        }
      }
      cout << endl;
    }

    cout << endl;
  }

  return 0;
}