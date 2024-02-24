#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const i64 MOD = 1e9 + 7;

unordered_map<i64, i64> fmem;

i64 fact(i64 n) {
  if (n == 0 or n == 1) {
    return 1;
  }

  if (fmem.count(n)) {
    return fmem[n];
  }

  return fmem[n] = (((n % MOD) * fact(n - 1)) % MOD);
}

i64 bpow(i64 n, i64 k) {
  if (k == 0) {
    return 1;
  }

  if (k == 1) {
    return n % MOD;
  }

  if (k % 2 == 0) {
    i64 x = bpow(n, k / 2);
    return (x * x) % MOD;
  } else {
    return ((n % MOD) * bpow(n, k - 1)) % MOD;
  }
}

i64 ifact(i64 n) {
  i64 x = fact(n);

  return bpow(x, MOD - 2);
}

i64 comb(i64 n, i64 k) {
  if (n < k) {
    return 0;
  }

  if (n == k or k == 0) {
    return 1;
  }

  if (k == 1) {
    return n % MOD;
  }

  return (((fact(n) * ifact(n - k)) % MOD) * ifact(k)) % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    i64 sum = n;
    i64 nr_5 = 0;
    i64 sol = 0;

    while (nr_5 <= n) {
      if (sum % 3 == 0) {
        sol = (sol + comb(n, nr_5)) % MOD;
      }
      nr_5++;
      sum += 4;
    }

    cout << sol << "\n";
  }
  return 0;
}
