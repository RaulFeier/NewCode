#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  string ch = "abcdefgh";
  while (tc--) {
    string s;
    cin >> s;

    i64 a = s[1] - '0';
    char c = s[0];

    i64 b = a - 1;
    while (b >= 1) {
      cout << c << b << endl;
      b--;
    }

    b = a + 1;
    while (b <= 8) {
      cout << c << b << endl;
      b++;
    }

    for (auto &e : ch) {
      if (c == e) {
        continue;
      } else {
        cout << e << a << endl;
      }
    }

    i64 ccc;
  }

  return 0;
}