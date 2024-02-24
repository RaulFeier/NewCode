#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    i64 first = -1;
    i64 end = -1;

    for (i64 i = 1; i <= n; i++) {
      char c;
      cin >> c;

      if (first == -1 and c == 'B') {
        first = i;
      }

      if (c == 'B') {
        end = i;
      }
    }

    cout << end - first + 1 << endl;
  }

  return 0;
}
