/**
 *    author:  BERNARD B.01
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef B01
#include "deb.h"
#else
#define deb(...)
#endif

struct dsu {
  int ncc;
  vector<int> p;

  dsu(int n) : ncc(n) {
    p.assign(n, -1);
  }

  inline int get(int x) {
    return (p[x] < 0 ? x : (p[x] = get(p[x])));
  }

  inline void unite(int x, int y) {
    if ((x = get(x)) != (y = get(y))) {
      if (p[x] < p[y]) {
        swap(x, y);
      }
      ncc -= 1;
      p[y] += p[x];
      p[x] = y;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //const int MAXC = (int) 1e9;
  //const int MAXN = (int) 2e5;
  int R, C, n;
  cin >> R >> C >> n;
  //assert(1 <= R && R <= MAXC);
  //assert(1 <= C && C <= MAXC);
  //assert(1 <= n && n <= MAXN);
  //assert(1 <= n && n <= (long long) R * C);
  map<int, vector<int>> mp[4];
  //set<pair<int, int>> se;
  for (int i = 0; i < n; i++) {
    int r, c;
    cin >> r >> c;
    //assert(1 <= r && r <= R);
    //assert(1 <= c && c <= C);
    //se.emplace(r, c);
    mp[0][r].push_back(i);
    mp[1][c].push_back(i);
    mp[2][r - c].push_back(i);
    mp[3][r + c].push_back(i);
  }
  //assert((int) se.size() == n);
  dsu d(n);
  for (int k = 0; k < 4; k++) {
    for (const auto& [_, v] : mp[k]) {
      for (int i = 0; i < (int) v.size() - 1; i++) {
        d.unite(v[i], v[i + 1]);
      }
    }
  }
  const int md = (int) 1e9 + 7;
  int ans = 1;
  for (int i = 0; i < d.ncc; i++) {
    ans += ans;
    if (ans >= md) {
      ans -= md;
    }
  }
  cout << ans << '\n';
  return 0;
}
