#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main() {
  i64 n, s, r;

  cin >> n >> s >> r;

  vector<i64> z(s);

  for (i64 i = 0; i < s; i++) {
    cin >> z[i];
  }

  vector<i64> v(r);

  for (i64 i = 0; i < r; i++) {
    cin >> v[i];
  }

  i64 t = 0;

  for (i64 i = 0; i < z.size(); i++) {
    for (i64 j = 0; j < v.size(); j++) {
      if (z[i] == v[j]) {
        v.erase(v.begin() + j);
        z.erase(z.begin() + i);
        t = 1;
        i--;
      }
    }
    if (t == 0) {
      for (i64 j = 0; j < v.size(); j++) {
        if (z[i] + 1 == v[j]) {
          v.erase(v.begin() + j);
          z.erase(z.begin() + i);
          i--;
        } else if (z[i] - 1 == v[j]) {
          v.erase(v.begin() + j);
          z.erase(z.begin() + i);
          i--;
        }
      }
    }
    t = 0;
  }

  cout << z.size() << endl;
  return 0;
}