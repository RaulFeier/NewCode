#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

class UnionFind {
private:
  vector<i64> p, rank;
  i64 numSets;

public:
  UnionFind(i64 n) {
    p.assign(n, 0);
    for (i64 i = 0; i < n; i++)
      p[i] = i;
    rank.assign(n, 0);
    numSets = n;
  }

  i64 findSet(i64 i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  i64 numOfSets() { return numSets; }

  void unionSet(int i, int j) {
    if (isSameSet(i, j))
      return;
    i64 x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y])
      swap(x, y);
    p[x] = y;
    if (rank[x] == rank[y])
      ++rank[y];
    --numSets;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 m, c;
    cin >> m >> c;

    i64 tct = (c * (c - 1)) / 2;

    vector<tuple<i64, i64, i64>> mst;
    for (i64 i = 0; i < tct; i++) {
      i64 u, v, w;
      cin >> u >> v >> w;
      mst.emplace_back(w, u, v);
    }

    sort(mst.begin(), mst.end());

    UnionFind uf(c);
    i64 total_cost = 0;

    for (auto &[w, u, v] : mst) {
      if (uf.isSameSet(u, v)) {
        continue;
      }
      total_cost += w;
      uf.unionSet(u, v);

      if (uf.numOfSets() == 1)
        break;
    }

    cout << ((total_cost + c <= m) ? "yes" : "no") << endl;
  }

  return 0;
}