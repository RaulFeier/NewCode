#include <bits/stdc++.h>

using namespace std;
using int64 = long;
using graph = vector<vector<int64>>;

enum class color { white, red, black };

color opposite_of(color c) {
  switch (c) {
  case color::red:
    return color::black;

  case color::black:
    return color::red;

  default:
    return color::white;
  }
}

class ujs {
private:
  vector<int64> v;
  vector<int64> rank;
  int64 components;

public:
  ujs(int64 size) {
    v.assign(size, -1);
    rank.assign(size, 0);
    components = size - 1;
  }

  int find(int64 n) {
    if (v[n] == -1) {
      return n;
    }

    v[n] = find(v[n]);
    return v[n];
  }

  inline void unite(int64 x, int64 y) {
    x = find(x);
    y = find(y);

    if (x == y) {
      return;
    }

    components -= 1;

    if (rank[x] < rank[y]) {
      v[x] = y;
      rank[y] += 1;
    } else {
      v[y] = x;
      rank[x] += 1;
    }
  }

  inline int64 count() { return components; }
};

bool is_bipartite(int64 start, graph &g, vector<bool> &vis) {
  vector<color> colors(g.size(), color::white);

  queue<int64> q;
  vis[start] = true;
  q.push(start);
  colors[start] = color::red;

  bool res = true;
  while (!q.empty()) {
    int64 node = q.front();
    q.pop();
    vis[node] = true;

    for (auto next : g[node]) {
      if (colors[next] == colors[node]) {
        res = false;
      }

      if (vis[next]) {
        continue;
      }

      q.push(next);
      vis[next] = true;
      colors[next] = opposite_of(colors[node]);
    }
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int64 n, m;
  scanf("%ld %ld", &n, &m);
  graph g(n + 1);
  ujs components(n + 1);
  for (int64 i = 0; i < m; i++) {
    int64 x, y;
    scanf("%ld %ld", &x, &y);

    g[x].push_back(y);
    g[y].push_back(x);
    components.unite(x, y);
  }

  vector<bool> vis(n + 1, 0);
  bool bipartite = true;
  for (int64 i = 1; i <= n; i++) {
    if (vis[i]) {
      continue;
    }

    if (!is_bipartite(i, g, vis)) {
      bipartite = false;
      break;
    }
  }

  if (bipartite) {
    printf("%ld\n", components.count());
  } else {
    printf("%ld\n", components.count() - 1);
  }

  return 0;
}