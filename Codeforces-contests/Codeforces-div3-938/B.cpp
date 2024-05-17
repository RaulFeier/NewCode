#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n, c, d;
    cin >> n >> c >> d;

    vector<i64> v(n * n);
    for (i64 i = 0; i < n * n; i++) {
      cin >> v[i];
    }
  }

  return 0;
}

/*
3 2 3
3 9 6 5 7 1 11 4 8

1 3 4 5 6 7 8 9 11
*/