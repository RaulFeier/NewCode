#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    i64 ans = 0;

    for (i64 i = 0; i < n; i++) {
      char a;
      cin >> a;
      ans += a == '+' ? 1 : -1;
    }

    cout << abs(ans) << endl;
  }

  return 0;
}

/*
-1 -1 1 1 1 1 1 1 1 -1
*/