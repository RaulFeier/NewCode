#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
#define endl '\n'

int main() {
  ifstream cin{"tnia.in"};
  ofstream cout{"tnia.out"};

  i32 n, m;
  cin >> n >> m;

  vector<vector<i32>> pref(m, vector<i32>(n, 0));

  for (i32 i = 0; i < n; i++) {
    i32 h;
    cin >> h;

    for (i32 j = 0; j < h; j++) {
      pref[j][i] = 1;
    }
  }

  for (i32 i = 1; i < m; i++) {
    pref[i][0] += pref[i - 1][0];
  }
  for (i32 j = 1; j < n; j++) {
    pref[0][j] += pref[0][j - 1];
  }

  for (i32 i = 1; i < m; i++) {
    for (i32 j = 1; j < n; j++) {
      pref[i][j] =
          pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + pref[i][j];
    }
  }

  i32 q;
  cin >> q;
  while (q--) {
    i32 x1, y1, x2, y2;
    i32 res;
    cin >> y1 >> x1 >> y2 >> x2;

    x1--;
    x2--;
    y1--;
    y2--;

    if (x1 && x2 && y1 && y2) {
      res = pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] +
            pref[x1 - 1][y1 - 1];
    } else if (x1 == 0 && y1 == 0) {
      res = pref[x2][y2];
    } else if (y1 == 0) {
      res = pref[x2][y2] - pref[x1 - 1][y2];
    } else if (x1 == 0) {
      res = pref[x2][y2] - pref[x2][y1 - 1];
    }

    cout << res << endl;
  }

  return 0;
}