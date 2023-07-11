#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using vi64 = vector<i64>;

i64 findSet(i64 a, vi64 &p) {
  return (p[a] == a) ? a : (p[a] = findSet(p[a], p));
}

bool isSameSet(i64 a, i64 b, vi64 &p) {
  if (findSet(a, p) == findSet(b, p)) {
    return true;
  }
  return false;
}

void unionSet(i64 a, i64 b, vi64 &p, vi64 &r) {
  i64 x = findSet(a, p), y = findSet(b, p);
  if (x == y) {
    return;
  }

  if (r[x] > r[y]) {
    swap(x, y);
  }
  p[x] = y;
  if (r[x] == r[y]) {
    r[y]++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  i64 n, q;
  cin >> n >> q;

  vector<i64> p(n);
  vector<i64> r(n);

  for (i64 i = 0; i < n; i++) {
    p[i] = i;
    r[i] = 1;
  }

  for (i64 tcc = 0; tcc < q; tcc++) {
    char chr;
    i64 a, b;
    cin >> chr >> a >> b;

    if (chr == '=') {
      unionSet(a, b, p, r);
    } else {
      if (isSameSet(a, b, p)) {
        cout << "yes" << '\n';
      } else {
        cout << "no" << '\n';
      }
    }
  }

  return 0;
}
