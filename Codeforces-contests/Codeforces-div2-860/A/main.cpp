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
    i64 n;
    cin >> n;

    vector<i64> a(n);

    for (i64 i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<i64> b(n);

    for (i64 i = 0; i < n; i++) {
      cin >> b[i];
    }

    for (i64 i = 0; i < n; i++) {
      if (a[i] > b[i]) {
        swap(a[i], b[i]);
      }
    }

    i64 max_a = 0;
    i64 max_b = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > max_a) {
        max_a = a[i];
      }
      if (b[i] > max_b) {
        max_b = b[i];
      }
    }

    if (a[a.size() - 1] == max_a and b[a.size() - 1] == max_b) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}