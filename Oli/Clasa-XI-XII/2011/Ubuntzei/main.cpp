// Misu boss
#include <bits/stdc++.h>

using namespace std;
using i16 = short;
using i32 = int;
using i64 = long long;

vector<i64> dij(i64 s, const vector<vector<pair<i16, i32>>> &g) {
  vector<i64> distances(g.size(), 1e18);
  priority_queue<pair<i16, i32>, vector<pair<i16, i32>>,
                 greater<pair<i16, i32>>>
      pq;

  distances[s] = 0;
  pq.emplace(0, s);

  while (!pq.empty()) {
    auto crt = pq.top();
    pq.pop();
    auto dist = crt.first;
    auto node = crt.second;

    if (dist > distances[node]) {
      continue;
    }

    for (auto &c : g[node]) {
      auto cand = dist + c.second;
      if (cand < distances[c.first]) {
        distances[c.first] = cand;
        pq.emplace(cand, c.first);
      }
    }
  }

  return distances;
}

int main() {
  ifstream cin{"ubuntzei.in"};
  ofstream cout{"ubuntzei.out"};

  i16 n, m;
  cin >> n >> m;
  i16 k;
  cin >> k;

  unordered_set<i16> v(k);
  for (i16 i = 0; i < k; i++) {
    i16 x;
    cin >> x;
    x--;
    v.insert(x);
  }

  vector<vector<pair<i16, i32>>> route(n);
  for (i16 i = 0; i < m; i++) {
    i16 x, y;
    i32 p;
    cin >> x >> y >> p;
    x--;
    y--;
    route[x].push_back({y, p});
  }

  i16 s = 0;
  i64 total = 0;

  vector<i64> distances = dij(s, route);

  for (auto x : v) {
    total += distances[x];
  }

  cout << total + distances[n - 1] << endl;

  return 0;
}