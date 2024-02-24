#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 n, k;
  cin >> n >> k;

  vector<i64> v(n);

  i64 start;
  for (i64 i = 0; i < n; i++) {
    cin >> v[i];

    if (v[i] == k) {
      start = i;
    }
  }

  map<i64, i64> m;
  m[0] = 1;

  i64 sum = 0;

  for (i64 i = start + 1; i < n; i++) {
    if (v[i] > k) {
      sum++;
    } else {
      sum--;
    }

    m[sum]++;
  }

  i64 ans = m[0];
  sum = 0;

  for (i64 i = start - 1; i >= 0; i--) {
    if (v[i] > k) {
      sum++;
    } else {
      sum--;
    }

    ans += m[-sum];
  }

  cout << ans << endl;

  return 0;
}

/*
5 7 2 4 3 1 6
m[-1] = 2
m[-2] = 1
*/
