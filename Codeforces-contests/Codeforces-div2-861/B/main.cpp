#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n, m;
    cin >> n >> m;

    vector<vector<i64>> cards(n, vector<i64>(m));

    for (i64 i = 0; i < n; i++) {
      for (i64 j = 0; j < m; j++) {
        cin >> cards[i][j];
      }
    }

    i64 cnt = 0;

    short eep = 0;
    i64 crt = 0;
    for (eep = 0; eep < n; eep++) {
      for (i64 i = eep + 1; i < n; i++) {
        for (i64 x = 0; x < m; x++) {
          crt += abs(cards[i][x] - cards[eep][x]);
        }
        cnt += crt;
        crt = 0;
      }
    }

    cout << cnt << endl;
  }

  return 0;
}

/*
3 5
1 4 2 8 5
7 9 2 1 4
3 8 5 3 1
*/