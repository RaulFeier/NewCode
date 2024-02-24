#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    vector<i64> a(2 * n);

    for (i64 i = 0; i < 2 * n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    i64 sum = 0;
    for (i64 i = a.size() - 1; i >= 0; i--) {
      if (i % 2 == 0) {
        sum += a[i];
      }
    }

    cout << sum << endl;
  }

  return 0;
}

// 5 9 2 6 27 8 3 5 9 10 5
// 1 2 3 5 5 5         6 8 9 9 19 27