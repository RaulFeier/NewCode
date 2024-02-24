#include <bits/stdc++.h>
#define vec vector
using namespace std;
using i64 = int64_t;
const i64 INF = 1e18;
typedef pair<i64, i64> pi64;
i64 s, t, k;

vec<vec<i64>> dij(vec<vec<pi64>> &g) {
  vec<vec<i64>> ans(g.size(), vec<i64>(k + 1, INF)); // here is the magic
  priority_queue<pair<i64, pi64>, vec<pair<i64, pi64>>,
                 greater<pair<i64, pi64>>>
      q;
  ans[s][1] = 0;
  q.push({0, {1, s}});

  while (!q.empty()) {
    auto p = q.top();
    q.pop();
    i64 dist = p.first;
    i64 steps = p.second.first;
    i64 node = p.second.second;

    if (node == t) {
      break; // avem sol
    }

    if (steps + 1 <= k) {
      for (auto &e : g[node]) {
        i64 sum = dist + e.second;
        if (sum < ans[e.first][steps + 1]) {
          ans[e.first][steps + 1] = sum;
          q.push({sum, {steps + 1, e.first}});
        }
      }
    }
  }

  return ans;
}

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;
    vec<vec<pi64>> g(n);

    for (i64 node = 0; node < n; node += 1) {
      i64 nn;
      cin >> nn;
      for (i64 i = 0; i < nn; i += 1) {
        i64 v, w;
        cin >> v >> w;
        g[node].push_back({v, w});
        // cout<<node<<" "<<v<<" "<<w<<endl;
      }
    }
    i64 q;
    cin >> q;

    for (i64 i = 0; i < q; i += 1) {
      cin >> s >> t >> k;
      auto res = dij(g);
      i64 r = INF;

      for (int j = 1; j <= k; j++) {
        r = min(r, res[t][j]);
      }
      if (r < INF) {
        cout << r << endl;
      } else {
        cout << -1 << endl;
      }
    }

    cout << endl;
  }
  return 0;
}