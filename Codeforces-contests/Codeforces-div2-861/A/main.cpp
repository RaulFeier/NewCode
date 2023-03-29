#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

i64 result(i64 l, i64 r) {
  i64 res = -1, nr;
  for (i64 i = r; i >= l; i--) {
    str s = to_string(i);
    sort(s.begin(), s.end());

    if (s[0] == '0' && s[s.size() - 1] == '9') {
      return i;
    }

    i64 a = (s[s.size() - 1] - '0') - (s[0] - '0');
    if (a > res) {
      res = a;
      nr = i;
    }
  }

  return nr;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 l, r;
    cin >> l >> r;

    cout << result(l, r) << endl;
  }

  return 0;
}
