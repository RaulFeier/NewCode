#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using p64 = pair<i64, i64>;

class UnionFind {
private:
  vector<i64> p, rank;

public:
  UnionFind(i64 n) {
    p.assign(n, 0);
    for (i64 i = 0; i < n; i++)
      p[i] = i;
    rank.assign(0, n);
  }

  i64 findSet(i64 x) { return (p[x] == x) ? x : (p[x] = findSet(p[x])); }
  bool ifSameSet(i64 x, i64 y) { return findSet(x) == findSet(y); }

  void unionSet(i64 x, i64 y) {
    if (ifSameSet(x, y))
      return;
    i64 a = findSet(x);
    i64 b = findSet(y);

    if (rank[a] > rank[b]) {
      swap(a, b);
    }
    p[a] = b;

    if (rank[a] == rank[b]) {
      ++rank[b];
    }
  }
};

vector<i64> dij(i64 s, vector<vector<p64>> &g) {
  vector<i64> ans(g.size(), 1e9);
  priority_queue<p64, vector<p64>, greater<p64>> pq;

  ans[s] = 0;
  pq.push({0, s});

  while (!pq.empty()) {
    auto crt = pq.top();
    pq.pop();

    if (crt.first > ans[crt.second]) {
      continue;
    }

    for (auto &c : g[crt.second]) {
      i64 cand = crt.first + c.second;
      if (cand < ans[c.first]) {
        ans[c.first] = cand;
        pq.push({cand, c.first});
      }
    }
  }

  return ans;
}

int main() { return 0; }
