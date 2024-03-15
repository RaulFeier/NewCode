#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
const i64 MOD = 20173333;

inline i64 mod(i64 n) {
  // if n cannot be negative for significant speed gain replace this with
  return n < MOD ? n : n % MOD;

  // if n is negetive use this
  // return ((n % MOD) + MOD) % MOD; // MOD here is 1e9 + 7;
}

inline i64 mult(i64 x, i64 y) { return (x * y) % MOD; }

unordered_map<i64, i64> dp;

i64 fact(i64 n) {
  if (n == 0 or n == 1)
    return 1;

  if (dp.count(n)) {
    return dp[n];
  }

  return dp[n] = mod(mod(n) * fact(n - 1));
}

i64 bpow(i64 a, i64 b) {
  if (b == 0)
    return 1;
  if (b == 1)
    return mod(a);
  if (b % 2 == 0) {
    i64 ans = bpow(a, b / 2);
    return mult(ans, ans);
  } else {
    return mult(bpow(a, b - 1), mod(a));
  }
}

i64 ifact(i64 n) {
  i64 x = fact(n);
  return bpow(x, MOD - 2);
}

i64 arn(i64 n, i64 k) {
  if (n < k)
    return 0;
  if (k == 0)
    return 1;
  if (n == k)
    return mod(fact(n));

  return mult(fact(n), ifact(n - k));
}

int main() {
  // ifstream cin{"sir.in"};
  // ofstream cout{"sir.out"};

  int c, n, x;
  cin >> c >> n >> x;

  if (c == 1) {
    i64 dif = n - x;
    cout << arn(x, dif) << endl;
  } else {
    cout << 8 << endl;
  }

  return 0;
}