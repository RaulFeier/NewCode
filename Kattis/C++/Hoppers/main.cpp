#include <bits/stdc++.h>

using namespace std;
using i64 = int;

class UnionFind {
private:
  vector<i64> p, rank, setSize;
  i64 numSets;

public:
  UnionFind(i64 n) {
    p.assign(n, 0);
    for (i64 i = 0; i < n; i++)
      p[i] = i;
    rank.assign(n, 0);
    setSize.assign(n, 1);
    numSets = n;
  }

  i64 findSet(i64 i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  i64 numDisjointSets() { return numSets; }
  i64 sizeOfSet(i64 i) { return setSize[findSet(i)]; }

  void unionSet(int i, int j) {
    i64 x = findSet(i), y = findSet(j);

    if (x == y) {
      return;
    }
    if (rank[x] > rank[y])
      swap(x, y);
    p[x] = y;
    if (rank[x] == rank[y])
      ++rank[y];
    setSize[y] += setSize[x];
    --numSets;
  }
};

bool isBipartite(i64 node, vector<i64> &color, vector<vector<i64>> &g) {
  queue<i64> q;
  q.push(node);
  color[node] = 0;

  bool isBipartit = true;

  while (!q.empty()) {
    auto crt = q.front();
    q.pop();

    for (auto &c : g[crt]) {
      if (color[c] == 1e9) {
        color[c] = 1 - color[crt];
        q.push(c);
      } else if (color[c] == color[crt]) {
        isBipartit = false;
      }
    }
  }

  if (isBipartit) {
    return true;
  } else {
    return false;
  }
}

i64 solve(vector<vector<i64>> &g, i64 n, UnionFind &uf) {
  bool ok = true;
  vector<i64> color(n + 1, 1e9);

  for (i64 i = 1; i <= n; i++) {
    if (color[i] == 1e9) {
      if (!isBipartite(i, color, g)) {
        ok = false;
      }
      if (!ok) {
        break;
      }
    }
  }

  if (!ok) {
    return uf.numDisjointSets() - 2;
  } else {
    return uf.numDisjointSets() - 1;
  }
}

int main() {
  i64 n, m;
  scanf("%d %d", &n, &m);

  vector<vector<i64>> g(n + 1);

  UnionFind uf(n + 1);

  for (i64 i = 0; i < m; i++) {
    i64 a, b;
    scanf("%d %d", &a, &b);

    g[a].push_back(b);
    g[b].push_back(a);
    uf.unionSet(a, b);
  }

  cout << solve(g, n, uf) << endl;

  return 0;
}
