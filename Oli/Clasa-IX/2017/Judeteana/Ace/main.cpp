#include <bits/stdc++.h>

using namespace std;

int solve1(short &n, short &m, vector<vector<short>> &v) {
  int crt = (n - 1) + (m - 1);
  short eep = 1;
  for (short i = n - 3; i >= 0; i--) {
    if (v[i][m - 1] <= v[i + 1][m - 1] + eep) {
      crt -= i + 1;
      break;
    }
    eep += 2;
  }
  eep = 1;
  for (short i = m - 3; i >= 0; i--) {
    if (v[n - 1][i] <= v[n - 1][i + 1] + eep) {
      crt -= i + 1;
      break;
    }
    eep += 2;
  }
  return crt;
}

int solve2(short &n, short &m, vector<vector<short>> &v) {
  int crt = n * m - 1;
  for (short i = n - 3; i >= 0; i--) {
    for (short j = n - 2; j > i; j--) {
      if (v[i][m - 1] <= v[j][m - 1] + 3) {
        crt--;
        break;
      }
    }
  }
  for (short i = m - 3; i >= 0; i--) {
    for (short j = m - 2; j > i; j--) {
      if (v[n - 1][i] <= v[n - 1][j] + 3) {
        crt--;
        break;
      }
    }
  }
  if (n == m) {
    for (short i = n - 3; i >= 0; i--) {
      for (short j = n - 2; j > i; j--) {
        if (v[i][i] <= v[j][j] + 3) {
          crt--;
          break;
        }
      }
    }
  } else {
    for (short i = n - 3; i > 0; i--) {
      for (short j = n - 2; j > i; j--) {
        if (v[i][i - 1] <= v[j][j - 1] + 3) {
          crt--;
          break;
        }
      }
    }
  }
  return crt;
}

int main() {
  ifstream cin{"ace.in"};
  ofstream cout{"ace.out"};
  short n, m;
  int8_t p;
  cin >> p >> n >> m;
  vector<vector<short>> v(n, vector<short>(m));
  for (short i = 0; i < n; i++) {
    for (short j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
  if (p == '1') {
    cout << solve1(n, m, v) << endl;
  } else {
    cout << solve2(n, m, v) << endl;
  }
  return 0;
}
