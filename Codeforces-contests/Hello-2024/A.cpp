#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 a, b;
    cin >> a >> b;

    if ((a + b) % 2 == 0) {
      cout << "Bob" << endl;
    } else {
      cout << "Alice" << endl;
    }
  }

  return 0;
}