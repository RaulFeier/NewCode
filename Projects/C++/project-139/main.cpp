#include <bits/stdc++.h>

using namespace std;

using i6 = long long;
using p6 = pair<i6, i6>;
using pp6 = pair<i6, p6>;
using vi6 = vector<i6>;
using vp6 = vector<p6>;
const i6 INF = 1e9;

i6 n, m;

i6 res[1001][101];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifdef LOCAL
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};
#endif
  cin >> n >> m;
  vi6 p(n);

  for (auto &c : p) {
    cin >> c;
  }

  vector<vp6> g(n + 1);
  for (i6 i = 0; i < m; i++) {
    i6 src, des, dist;
    cin >> src >> des >> dist;
    g[src].push_back({des, dist});
    g[des].push_back({src, dist});
  }

  i6 q;
  cin >> q;

  for (i6 qi = 0; qi < q; qi++) {
    i6 st, fin, c;
    cin >> c >> st >> fin;

    for (int u = 0; u <= n; u++) {
      for (int k = 0; k <= c; k++) {
        res[u][k] = INF;
      }
    }

    res[st][0] = 0;
    priority_queue<pp6, vector<pp6>, greater<pp6>> que;
    que.push({0, {st, 0}});

    while (!que.empty()) {
      auto crt = que.top();
      i6 cost = crt.first;
      i6 citi = crt.second.first;
      i6 fuel = crt.second.second;
      que.pop();

      if (citi == fin) {
        break;
      }

      if (res[citi][fuel] < cost) {
        continue;
      }

      if (fuel < c) {
        if (cost + p[citi] < res[citi][fuel + 1]) {
          res[citi][fuel + 1] = cost + p[citi];
          que.push({cost + p[citi], {citi, fuel + 1}});
        }
      }

      for (auto &nx : g[citi]) {
        i6 nx_c = nx.first;
        i6 nx_d = nx.second;
        if (fuel - nx_d >= 0 && cost < res[nx_c][fuel - nx_d]) {
          res[nx_c][fuel - nx_d] = cost;
          que.push({cost, {nx_c, fuel - nx_d}});
        }
      }
    }

    i6 sol = INF;

    for (int i = 0; i <= c; i++) {
      sol = min(sol, res[fin][i]);
    }

    if (sol >= INF) {
      cout << "impossible" << endl;
    } else {
      cout << sol << endl;
    }
  }
  return 0;
}
