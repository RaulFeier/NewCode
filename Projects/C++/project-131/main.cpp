#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    i64 l = 1;
    i64 r = n;
    for (i64 i = 0; i < n; i++) {
      if (i % 2 == 0) {
        cout << l << " ";
        l++;
      } else {
        cout << r << " ";
        r--;
      }
    }
    cout << endl;
  }

  return 0;
}