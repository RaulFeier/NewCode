#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
const int P = 101;
const int N = 2e6 + 1;

int n, m, p, r, inp, fac[N], inv[N], dp[P][P][P];

int fpow(int b, int p = mod - 2) {
    ll res = 1;
    ll pow = b;
    for (; p; p >>= 1) {
        if (p & 1) {
            res = res * pow % mod;
        }
        pow = pow * pow % mod;
    }
    return res;
}

void precalc() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = 1ll * fac[i - 1] * i % mod;
    }
    inv[N - 1] = fpow(fac[N - 1]);
    for (int i = N - 2; i >= 0; --i) {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
    }
}

int choose(int n, int k) {
    return 1ll * fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int calc(int n, int m, int r) {
    if (!m || !n) {
        return !r;
    }
    if (dp[n][m][r] != -1) {
        return dp[n][m][r];
    }
    ll res = 0;
    res += calc(n - 1, m, r);
    res += calc(n, m - 1, (r - n + p) % p);
    return dp[n][m][r] = res % mod;
}

int main() {
    cin >> n >> m >> p >> r;
    inp = fpow(p);

    precalc();
    memset(dp, -1, sizeof dp);

    ll same = choose(n / p + m / p, n / p);
    ll ans = (choose(n + m, n) - same * choose(n % p + m % p, n % p) % mod) * inp % mod;
    (((ans += same * calc(n % p, m % p, r) % mod) %= mod) += mod) %= mod;

    cout << ans << "\n";
}
