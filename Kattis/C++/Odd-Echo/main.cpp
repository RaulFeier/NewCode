#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 n;
  cin >> n;

  for (i64 i = 1; i <= n; i++) {
    string ans;
    cin >> ans;
    if (i % 2 == 1) {
      cout << ans << "\n";
    }
  }
  return 0;
}