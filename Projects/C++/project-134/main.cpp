#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ft first
#define sd second
#define sz(x) (i6) x.size()
#define col(x) x.begin(), x.end()
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())
#define rvs(x) reverse(x.begin(), x.end())
#define LSOne(S) ((S) & (-S))

template <typename T> using vec = vector<T>;
template <typename T> using deq = deque<T>;

typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef string str;
typedef pair<i64, i64> p64;
typedef vec<i64> vi64;
typedef vec<i32> vi32;
typedef vec<vi64> vv;
typedef vec<p64> vp64;
typedef vec<str> vstr;

i64 MOD = 998244353;
vi64 dp;

i64 mod_neg(i64 a) { return ((a % MOD) + MOD) % MOD; }

i64 mod(i64 a, i64 m) { return a < MOD ? a : a % MOD; }
i64 mod(i64 a) { return mod(a, MOD); }

i64 mult(i64 x, i64 y) { return (x * y) % MOD; }

i64 fact(i64 n) {
  if (n == 0 or n == 1)
    return 1;

  if (dp[n] != 0) {
    return dp[n];
  }

  return dp[n] = mod(mod(n) * fact(n - 1));
}

i64 bpow(i64 a, i64 b) {
  if (b == 0) {
    return 1;
  }
  if (b == 1) {
    return mod(a);
  }

  if (b % 2 == 0) {
    i64 ans = mod(bpow(a, b / 2));
    return mult(ans, ans);
  } else {
    return mult(bpow(a, b - 1), mod(a));
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
  if (k == 0 or n == k) {
    return 1;
  }
  if (k == 1) {
    return mod(n);
  }
  return mult(mult(fact(n), ifact(n - k)), ifact(k));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, k;
  cin >> n >> k;

  dp.assign(n, 0);

  map<i64, i64> o, c;
  for (i64 i = 0; i < n; i++) {
    i64 l, r;
    cin >> l >> r;
    o[l]++;
    c[r]++;
  }

  auto oit = o.begin();
  auto cit = c.begin();

  i64 open = 0;
  i64 tot = 0;

  while (cit != c.end()) {
    if (oit != o.end()) {
      if (oit->ft < cit->ft) {
        i64 pr = open;
        open += oit->sd;

        if (open >= k) {
          tot += mod_neg(comb(open, k) - comb(pr, k));
          tot = mod(tot);
        }

        oit++;
      } else if (oit->ft == cit->ft) {
        i64 pr = open;
        open += oit->sd;

        if (open >= k) {
          tot += mod_neg(comb(open, k) - comb(pr, k));
          tot = mod(tot);
        }

        open -= cit->sd;
        oit++;
        cit++;
      } else {
        open -= cit->sd;
        cit++;
      }
    } else {
      open -= cit->sd;
      cit++;
    }
  }

  cout << tot << endl;

  return 0;
}