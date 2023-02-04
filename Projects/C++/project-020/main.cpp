#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  for (int i = 0; i < tc; i++) {
    i64 n;
    cin >> n;
    vector<vector<string>> v(3, vector<string>(n));
    map<string, i64> m;

    for (int j = 0; j < n; j++) {
      cin >> v[0][j];
      m[v[0][j]] += 1;
    }
    for (int j = 0; j < n; j++) {
      cin >> v[1][j];
      m[v[1][j]] += 1;
    }
    for (int j = 0; j < n; j++) {
      cin >> v[2][j];
      m[v[2][j]] += 1;
    }

    i64 a = 0, b = 0, c = 0;
    for (i64 j = 0; j < n; j++) {
      if (m[v[0][j]] == 1) {
        a += 3;
      } else if (m[v[0][j]] == 2) {
        a += 1;
      }
      if (m[v[1][j]] == 1) {
        b += 3;
      } else if (m[v[1][j]] == 2) {
        b += 1;
      }
      if (m[v[2][j]] == 1) {
        c += 3;
      } else if (m[v[2][j]] == 2) {
        c += 1;
      }
    }

    cout << a << " " << b << " " << c << endl;
  }
  return 0;
}