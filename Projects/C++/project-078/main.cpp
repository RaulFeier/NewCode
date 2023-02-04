#include <bits/stdc++.h>

using namespace std;
typedef short sht;
typedef float fl;

short solve1(fl &n, fl &m, vector<vector<fl>> &v) {
  short crt = 0;
  float d1 = 1 / v[n - 2][m - 1];

  for (fl i = n - 3; i >= 0; i--) {
    fl d2 = (n - i) / v[i][m - 1];
    if (d1 > d2) {
      crt++;
      d1 = d2;
    }
  }

  d1 = 1 / v[n - 1][m - 2];

  for (fl i = m - 3; i >= 0; i--) {
    fl d2 = (m - i) / v[n - 1][m - i];
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

  fl n, m;
  char p;

  cin >> p >> n >> m;
  vector<vector<fl>> v(n, vector<fl>(m));

  for (short i = 0; i < n; i++) {
    for (short j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  if (p == '1') {
    cout << solve1(n, m, v) << endl;
  }

  return 0;
}