#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

template <typename T> using vec = vector<T>;

using i64 = long long;
using d64 = long double;
using vi64 = vec<i64>;

i64 cnt = 0;

void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

void dfs(i64 vertex, const vec<vec<i64>> &v, vec<bool> &visit) {
  if (!visit[vertex]) {
    visit[vertex] = true;
    cnt++;

    for (auto child : v[vertex]) {
      if (!visit[child]) {
        dfs(child, v, visit);
      }
    }
  }
}

void solve() {
  i64 n, m, l;
  cin >> n >> m >> l;

  vec<vec<i64>> v(n + 1, vec<i64>());

  for (i64 i = 0; i < m; i++) {
    i64 a, b;
    cin >> a >> b;
    v[a].push_back(b);
  }

  vec<bool> visit(n + 1, false);
  cnt = 0;
  while (l--) {
    i64 vertex;
    cin >> vertex;
    dfs(vertex, v, visit);
  }

  cout << cnt << endl;
}

int main() {
  fast();

  i64 tc;
  cin >> tc;

  while (tc--) {
    solve();
  }
  return 0;
}