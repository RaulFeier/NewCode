#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  for (i64 k = 1; k <= tc; k++) {
    i64 n;
    cin >> n;

    vector<i64> v1(n);
    vector<i64> v2(n);

    for (i64 i = 0; i < n; i++) {
      cin >> v1[i];
    }

    for (i64 i = 0; i < n; i++) {
      cin >> v2[i];
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    i64 total = 0;
    for (i64 i = 0; i < n; i++) {
      total += (v1[i] * v2[n - i - 1]);
    }

    cout << "Case #" << k << ": " << total << endl;
  }

  return 0;
}

/*
-5 1 3
4 1 -2

-20 + 1 - 6 = -25

1 2 3 4 5
1 1 1 0 0

1 + 2 + 3 = 6

5 8 10 23
9 8 5 2

-23 -10 -8 -5
-2 -5 -8 -9

*/
