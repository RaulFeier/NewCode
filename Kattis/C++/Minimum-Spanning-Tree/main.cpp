#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define let auto
#define endl '\n'

class UnionFind {
private:
  vector<i64> p, rank;

public:
  UnionFind(i64 n) {
    p.assign(n, 0);
    for (i64 i = 0; i < n; i++)
      p[i] = i;
    rank.assign(n, 0);
  }

  i64 findSet(i64 i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(i64 i, i64 j) { return findSet(i) == findSet(j); }

  void UnionSet(i64 i, i64 j) {
    if (isSameSet(i, j))
      return;
    i64 x = findSet(i);
    i64 y = findSet(j);
    if (rank[x] > rank[y])
      swap(x, y);
    p[x] = y;
    if (rank[x] == rank[y])
      ++rank[y];
  }
};

bool cmp(pair<i64, i64> p1, pair<i64, i64> p2) {
  if (p1.first == p2.first) {
    return p1.second < p2.second;
  }

  return p1.first < p2.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 n, m;

  while (cin >> n >> m) {
    if (n == 0 and m == 0) {
      break;
    }

    if (m == 0) {
      cout << "Impossible" << endl;
      continue;
    }

    vector<tuple<i64, i64, i64>> mst;

    for (i64 i = 0; i < m; i++) {
      i64 u, v, w;
      cin >> u >> v >> w;

      mst.push_back({w, u, v});
    }

    sort(mst.begin(), mst.end());

    UnionFind uf(n);
    i64 min_cost = 0;
    i64 nodes_taken = 0;

    vector<pair<i64, i64>> edges;

    for (let & [ w, u, v ] : mst) {
      if (uf.isSameSet(u, v)) {
        continue;
      }
      min_cost += w;
      edges.push_back({u, v});
      nodes_taken++;
      uf.UnionSet(u, v);

      if (nodes_taken == n - 1) {
        break;
      }
    }

    if (nodes_taken < n - 1) {
      cout << "Impossible" << endl;
      continue;
    }

    cout << min_cost << endl;

    for (let &x : edges) {
      if (x.first > x.second) {
        swap(x.first, x.second);
      }
    }

    sort(edges.begin(), edges.end(), cmp);

    for (let &x : edges) {
      cout << x.first << " " << x.second << endl;
    }
  }

  return 0;
}
