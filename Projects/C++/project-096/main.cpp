#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  i64 n, t;
  str s;
  cin >> t;

  while (t--) {
    bool ok = true, cool = false;
    i64 fm = -1, fe = -1, fo = -1, fw = -1;
    i64 lm = -1, le = -1, lo = -1, lw = -1;
    cin >> n >> s;

    if (s[0] == 'M' || s[0] == 'm') {
      lm = 0;
      fm = 0;

      for (i64 i = 0; i < n; i++) {
        if (s[i] == 'm' || s[i] == 'M') {
          lm = i;
        } else if (s[i] == 'e' || s[i] == 'E') {
          if (fe == -1) {
            fe = i;
          }
          le = i;
        } else if (s[i] == 'o' || s[i] == 'O') {
          if (fo == -1) {
            fo = i;
          }
          lo = i;
        } else if (s[i] == 'w' || s[i] == 'W') {
          if (fw == -1) {
            fw = i;
          }
          lw = i;
        } else {
          cout << "NO" << endl;
          ok = false;
          cool = true;
          break;
        }
      }

      if (cool) {
        continue;
      }

      if (fe != -1 && fo != -1 && fw != -1) {
        if (!(lm == fe - 1 && le == fo - 1 && lo == fw - 1)) {
          cout << "NO" << endl;
          ok = false;
        }
      } else {
        cout << "NO" << endl;
        ok = false;
      }
    } else {
      ok = false;
    }

    if (ok) {
      cout << "YES" << endl;
    }
  }

  return 0;
}