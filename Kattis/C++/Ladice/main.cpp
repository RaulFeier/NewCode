#include <bits/stdc++.h>

using namespace std;

class UnionFind {
private:
  vector<int> p;
  vector<int> setSize;
  int n;
  vector<int> Empty;

public:
  UnionFind(int n) {
    this->n = n;
    p.resize(n);
    setSize.resize(n, 1);

    for (int i = 0; i < n; i++) {
      p[i] = i;
      Empty.push_back(1);
    }
  }

  int FindSet(int x) { return (p[x] == x) ? x : (p[x] = FindSet(p[x])); }

  int Empty_Num(int x) { return Empty[FindSet(x)]; }

  int sizeOfSet(int x) { return setSize[FindSet(x)]; }

  void FillSet(int x) { Empty[FindSet(x)]--; }

  void Union(int x, int y) {
    int xset = FindSet(x);
    int yset = FindSet(y);

    if (xset == yset) {
      return;
    }

    p[xset] = yset;
    setSize[yset] += setSize[xset];
    Empty[yset] += Empty[xset];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, l;
  cin >> n >> l;

  UnionFind uf(l);
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    if (uf.sizeOfSet(u) == 1) {
      uf.FillSet(u);
      uf.Union(u, v);
    } else if (uf.sizeOfSet(v) == 1) {
      uf.FillSet(v);
      uf.Union(u, v);
    } else if (uf.Empty_Num(u) > 0) {
      uf.FillSet(u);
      uf.Union(u, v);
    } else if (uf.Empty_Num(v) > 0) {
      uf.FillSet(v);
      uf.Union(u, v);
    } else {
      cout << "SMECE" << '\n';
      continue;
    }

    cout << "LADICA" << '\n';
  }

  return 0;
}

/*
1 2 3 4 5 6 7 8 9 10
1 1 1 1 1 0 1 1 1 1
 */