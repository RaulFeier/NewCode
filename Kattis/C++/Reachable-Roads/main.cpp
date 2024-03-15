#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

class UnionFind {
private:
  vector<i64> p;
  i64 num_sets;

public:
  UnionFind(i64 n) {
    num_sets = n;
    p.assign(n, -1);

    for (i64 i = 0; i < n; i++)
      p[i] = i;
  }

  i64 find(i64 i) {
    while (i != p[i]) {
      i = p[i];
    }

    return i;
  }

  void join(i64 a, i64 b) {
    a = find(a);
    b = find(b);

    if (a != b) {
      p[a] = b;
      num_sets--;
    }
  }

  i64 sets() { return num_sets; }
};

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    i64 m;
    cin >> m;

    UnionFind uf(n);

    for (i64 i = 0; i < m; i++) {
      i64 a, b;
      cin >> a >> b;

      uf.join(a, b);
    }

    cout << uf.sets() - 1 << endl;
  }

  return 0;
}