#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 a, b;
    cin >> a >> b;

    if (a > b) {
      swap(a, b);
    }

    if (((a % 2 == 1) and (b % 2 == 1)) or ((a % 2 == 1) and (b == 2 * a))) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }

  return 0;
}