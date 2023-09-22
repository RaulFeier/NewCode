#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<i32> vi32;
typedef vector<vi64> vv;
typedef vector<vector<i32>> vv32;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n;
    cin >> n;

    i64 res = 1e9;
    for (i64 i = 0; i < n; i++) {
      i64 a, b;
      cin >> a >> b;

      i64 p = a + b / 2 - 1;

      if (b % 2 != 0) {
        res = min(res, p + 1);
      } else {
        res = min(res, p);
      }
    }

    cout << res << endl;
  }

  return 0;
}

// eep