#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    if (n % 3 == 1 or n % 3 == 2) {
      cout << "First" << endl;
    } else {
      cout << "Second" << endl;
    }
  }

  return 0;
}
