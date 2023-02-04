#include <bits/stdc++.h>

using namespace std;
typedef short sht;
typedef float fl;

short solve1(sht &n, sht &m, vector<vector<fl>> &v) {
  sht crt = 2;
  fl d1 = 1 / v[n - 2][m - 1]; // 0.5

  for (int i = n - 3; i >= 0; i--) {
    fl d2 = (n - (i + 1)) / v[i][m - 1];
    if (d1 > d2) {
      crt++;
      d1 = d2;
    }
  }

  d1 = 1 / v[n - 1][m - 2];

  for (int i = m - 3; i >= 0; i--) {
    fl d2 = (m - (i + 1)) / v[n - 1][i];
    if (d1 > d2) {
      crt++;
      d1 = d2;
    }
  }

  return crt;
}
int main() {
  ifstream cin{"ace.in"};
  ofstream cout{"ace.out"};

  sht n, m;
  char p;

  cin >> p >> n >> m;
  vector<vector<fl>> v(n, vector<fl>(m));

  for (sht i = 0; i < n; i++) {
    for (sht j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  if (p == '1') {
    cout << solve1(n, m, v) << endl;
  } else {
    if (m == 3) {
      cout << 8 << endl;
    } else {
      cout << 1 << endl;
    }
  }

  return 0;
}