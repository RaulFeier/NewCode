#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

class fenwick {
private:
  vector<int64_t> ft;

  int lsbl(i64 x) { return x & (-x); }

public:
  fenwick(i64 n) { ft.assign(n + 1, 0); }

  void update(i64 pos, i64 val) {
    i64 crt = pos + 1;
    while (crt < ft.size()) {
      ft[crt] += val;
      crt += lsbl(crt);
    }
  }

  i64 rsq(i64 pos) {
    i64 crt = pos + 1;
    i64 ans = 0;
    while (crt > 0) {
      ans += ft[crt];
      crt -= lsbl(crt);
    }
    return ans;
  }

  i64 rsq(i64 l, i64 r) { return rsq(r) - rsq(l - 1); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 n;
  cin >> n;

  vector<i64> v(n);

  for (auto &c : v) {
    cin >> c;
  }

  fenwick fl(n + 2);
  vector<i64> l(n, 0);

  for (i64 i = 0; i < n; i++) {
    l[i] = fl.rsq(v[i] + 1, n);
    fl.update(v[i], 1);
  }

  fenwick fr(n + 2);
  vector<i64> r(n, 0);

  for (i64 i = n - 1; i >= 0; i--) {
    r[i] = fr.rsq(v[i] - 1);
    fr.update(v[i], 1);
  }

  int64_t sol = 0;
  for (i64 i = 0; i < n; i++) {
    sol += (l[i] * r[i]);
  }

  cout << sol << endl;

  return 0;
}

/*
3 3 2 1

3 1 2 3
1 2 3 3
*/