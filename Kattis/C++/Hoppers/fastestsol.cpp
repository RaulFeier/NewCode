#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

unordered_set<i64> s;

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

bool isBipartite(vector<vector<i64>> &g, i64 node) {
  vector<i64> color(g.size(), 1e9);

  queue<i64> q;
  q.push(node);
  s.erase(node);
  color[node] = 0;

  while (!q.empty()) {
    auto crt = q.front();
    q.pop();

    for (auto &c : g[crt]) {
      if (color[c] == 1e9) {
        color[c] = 1 - color[crt];
        s.erase(c);
        q.push(c);
      } else if (color[c] == color[crt]) {
        return false;
      }
    }
  }

  return true;
}

i64 solve(vector<vector<i64>> &g, UnionFind &uf) {
  bool ok = true;
  vector<bool> visit(g.size(), false);

  while (!s.empty()) {
    for (auto &c : s) {
      if (!isBipartite(g, c)) {
        ok = false;
      }
      break;
    }
    if (!ok) {
      break;
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
  scanf("%lld %lld", &n, &m);

  vector<vector<i64>> g(n + 1);
  UnionFind uf(n + 1);

  for (i64 i = 0; i < m; i++) {
    i64 a, b;
    scanf("%lld %lld", &a, &b);

    g[a].push_back(b);
    g[b].push_back(a);
    s.insert(a);
    s.insert(b);
    uf.unionSet(a, b);
  }

  cout << solve(g, uf) << endl;

  return 0;
}

/*
 */
