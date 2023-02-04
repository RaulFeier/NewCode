#include <bits/stdc++.h>

using namespace std;

short solve1(short &n, short &m, vector<vector<short>> &v) {
  short crt = v[n - 2][m - 1];
  // nord
  for (int i = n - 3; i >= 0; i--) {
    if (v[i][m - 1] > crt)
  }
}

int main() {
  char cerinta;
  cin >> cerinta;

  short n, m;
  cin >> n >> m;
  vector<vector<short>> v(n, vector<short>(m));

  for (short i = 0; i < n; i++) {
    for (short j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }

  if (cerinta == '1') {
    cout << solve1(n, m, v) << endl;
  }
}