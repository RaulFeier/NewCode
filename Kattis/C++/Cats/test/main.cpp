#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define fast_cin()                                                             \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

class UnionFind { // OOP style
private:
  vi p, rank, setSize; // vi p is the key part
  int numSets;

public:
  UnionFind(int N) {
    p.assign(N, 0);
    for (int i = 0; i < N; ++i)
      p[i] = i;
    rank.assign(N, 0);    // optional speedup
    setSize.assign(N, 1); // optional feature
    numSets = N;          // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }            // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j))
      return;                           // i and j are in same set
    int x = findSet(i), y = findSet(j); // find both rep items
    if (rank[x] > rank[y])
      swap(x, y); // keep x 'shorter' than y
    p[x] = y;     // set x under y
    if (rank[x] == rank[y])
      ++rank[y];              // optional speedup
    setSize[y] += setSize[x]; // combine set sizes at y
    --numSets;                // a union reduces numSets
  }
};

int t, n, e, total_cost, milk_in_fridge;
vector<tuple<int, int, int>> el;
int main() {
  fast_cin();
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    el.clear();

    cin >> milk_in_fridge >> n;
    e = n * (n - 1) / 2; // complete graph

    for (int i = 0; i < e; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      el.emplace_back(w, u, v);
    }
    sort(el.begin(), el.end());
    UnionFind uf(n);
    total_cost = 0;

    for (auto &[w, u, v] : el) {
      if (uf.isSameSet(u, v))
        continue;
      total_cost += w;
      uf.unionSet(u, v);

      if (uf.numDisjointSets() == 1)
        break;
    }

    cout << ((total_cost + n <= milk_in_fridge) ? "yes" : "no") << endl;
  }
}