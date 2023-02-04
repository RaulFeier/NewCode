#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 a, b;
  cin >> a >> b;

  i64 cnt = 0;
  while (a != b) {
    if (a > b) {
      if (a % 2 == 0) {
        a /= 2;
        cnt++;
      } else {
        a += 1;
        cnt++;
        continue;
      }
    } else {
      a += 1;
      cnt++;
    }
  }

  cout << cnt << '\n';
  return 0;
}