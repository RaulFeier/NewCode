#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    char c;
    i64 d, h, m;
    cin >> c >> d >> h >> m;

    if (c == 'F') {
      m += d;
      while (m >= 60) {
        h++;
        m -= 60;
      }
      while (h >= 24) {
        h -= 24;
      }
    } else {
      m -= d;
      while (m < 0) {
        h--;
        m += 60;
      }
      while (h < 0) {
        h += 24;
      }
    }

    cout << h << " " << m << endl;
  }

  return 0;
}