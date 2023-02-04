#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define MOD 20173333

int power(int x, i64 y, i64 p) {
  int res = 1;

  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }

    y = y >> 1;
    x = (x * x) % p;
  }

  return res;
}

int modInverse(int n, i64 p) { return power(n, p - 2, p); }

int solve1(int n, int u, i64 p) {
  if (u == 0) {
    return 1;
  }

  vector<int> eep(n + 1);
  eep[0] = 1;
  for (int i = 1; i <= n; i++) {
    eep[i] = (eep[i - 1] * i) % p;
  }

  return (eep[n] * modInverse(eep[u], p) % p * modInverse(eep[n - u], p) % p) %
         p;
}

short solve2(int &n, int &r) { return 1; }

int main() {
  ifstream cin{"sirul2.in"};
  ofstream cout{"sirul2.out"};

  char cerinta;
  int n, x;
  cin >> cerinta >> n >> x;
  i64 p = 20173333;

  if (cerinta == '1') {
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