#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using p64 = pair<i64, i64>;
const i64 INF = 1e18;
#define endl '\n'

class point {
public:
  i64 w, j, node;
};

class cmp {
public:
  bool operator()(point x, point y) { return x.w > y.w; }
};

i64 dijkstra(i64 s, i64 t, i64 k, const vector<vector<p64>> &g) {
  priority_queue<point, vector<point>, cmp> pq;
  vector<vector<i64>> ans(g.size(), vector<i64>(k + 1, INF));

  ans[s][1] = 0;
  pq.push({0, 1, s});

  while (!pq.empty()) {
    auto crt = pq.top();
    pq.pop();

    if (crt.node == t) {
      break;
    }

    if (crt.j + 1 <= k) {
      for (auto &c : g[crt.node]) {
        i64 cand = c.second + crt.w;
        if (ans[c.first][crt.j + 1] > cand) {
          ans[c.first][crt.j + 1] = cand;
          pq.push({cand, crt.j + 1, c.first});
        }
      }
    }
  }

  i64 res = INF;
  for (i64 i = 1; i <= k; i++) {
    res = min(ans[t][i], res);
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    vector<vector<p64>> g(n);

    for (i64 i = 0; i < n; i++) {
      i64 m;
      cin >> m;

      for (i64 k = 0; k < m; k++) {
        i64 v, w;
        cin >> v >> w;

        g[i].push_back({v, w});
        // g[v].push_back({i, w});
      }
    }

    i64 q;
    cin >> q;

    while (q--) {
      i64 s, t, k;
      cin >> s >> t >> k;

      i64 sol = dijkstra(s, t, k, g);

      if (sol >= INF) {
        cout << -1 << endl;
      } else {
        cout << sol << endl;
      }
    }
    cout << endl;
  }

  return 0;
}