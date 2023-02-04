#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 parent(i64 x, vector<i64> &v) {
  i64 hp = x;
  i64 ans = v[x];
  while (ans != x) {
    x = ans;
    ans = v[ans];
  }
  v[hp] = ans;
  return ans;
}

i64 join(i64 x, i64 y, vector<i64> &v, vector<i64> &r) {
  i64 a1 = parent(x, v);
  i64 a2 = parent(y, v);

  if (a1 != a2) {
    if (r[a1] > r[a2]) {
      v[a2] = a1;
      r[a1] += r[a2];
      return r[a1];
    } else {
      v[a1] = a2;
      r[a2] += r[a1];
      return r[a2];
    }
  }
  return r[a1];
}

void fast() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main() {
  fast();
  i64 t;
  cin >> t;

  for (i64 i = 0; i < t; i++) {
    i64 w;
    cin >> w;
    vector<i64> v(2 * w);
    vector<i64> r(2 * w, 1);

    for (i64 z = 0; z < 2 * w; z++) {
      v[z] = z;
    }
    i64 d = 0;

    map<string, i64> n;
    for (i64 z = 0; z < w; z++) {
      string s1, s2;
      cin >> s1 >> s2;

      if (n.count(s1) == 0) {
        n[s1] = d;
        d++;
      }
      if (n.count(s2) == 0) {
        n[s2] = d;
        d++;
      }
      cout << join(n[s1], n[s2], v, r) << endl;
    }
  }
  return 0;
}