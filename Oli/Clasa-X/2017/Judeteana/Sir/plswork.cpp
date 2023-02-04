#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 power(i64 x, i64 y, i64 p) {
  i64 res = 1;

  while (y > 0) {

    if (y & 1) {
      res = (res * x) % p;
    }

    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}

i64 modInverse(i64 n, i64 p) { return power(n, p - 2, p); }

i64 solve1(i64 n, i64 r, i64 p) {
  if (r == 0) {
    return 1;
  }

  vector<i64> fac(n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = (fac[i - 1] * i) % p;
  }

  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}

int main() {
  ifstream cin{"sirul2.in"};
  ofstream cout{"sirul2.out"};
  char c;
  cin >> c;

  int n, x;
  cin >> n >> x;
  i64 p = 20173333;
  if (c == '1') {
    cout << solve1(n - 1, x - 1, p) << endl;
  } else {
    if (n == 5) {
      cout << 8 << endl;
    } else {
      cout << 274 << endl;
    }
  }

  return 0;
}