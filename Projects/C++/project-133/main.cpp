#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using i64 = int64_t;
const i64 MOD = 1e9 + 7;

inline i64 mod(i64 n) { return n < MOD ? n : n % MOD; }

gp_hash_table<i64, i64> fmem;

i64 fact(i64 n) {
  if (n == 0 or n == 1) {
    return 1;
  }

  auto f = fmem.find(n);
  if (f != fmem.end()) {
    return f->second;
  }

  return fmem[n] = mod(mod(n) * fact(n - 1));
}

i64 bpow(i64 n, i64 k) {
  if (k == 0) {
    return 1;
  }

  if (k == 1) {
    return mod(n);
  }

  if (k % 2 == 0) {
    i64 x = bpow(n, k / 2);
    return mod(x * x);
  } else {
    return mod(mod(n) * bpow(n, k - 1));
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
    return mod(n);
  }

  return mod(mod(fact(n) * ifact(n - k)) * ifact(k));
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
        sol = mod(sol + comb(n, nr_5));
      }
      nr_5++;
      sum += 4;
    }

    cout << sol << "\n";
  }
  return 0;
}
