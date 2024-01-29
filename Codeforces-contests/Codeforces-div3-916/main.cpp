#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n, k;
    cin >> n >> k;

    vector<bool> v(n + 1);
    for (i64 i = 1; i <= k; i++) {
      cout << i << " ";
      cout << n - (i - 1) << " ";
      v[i] = true;
      v[n - (i - 1)] = true;
    }

    for (i64 i = 1; i <= n; i++) {
      if (!v[i]) {
        cout << i << " ";
      }
    }

    cout << endl;
  }

  return 0;
}