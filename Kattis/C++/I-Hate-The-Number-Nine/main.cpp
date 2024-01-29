#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const i64 mod = 1e9 + 7;

i64 bpow(i64 n, i64 m) {
  if (m == 0) {
    return 1;
  }

  if (m == 1) {
    return n;
  }

  if (m % 2 == 0) {
    i64 res = bpow(n, m / 2);
    return (res * res) % mod;
  } else {
    return (n * bpow(n, m - 1)) % mod;
  }
}

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    cout << (bpow(9, n - 1) * 8) % mod << endl;
  }

  return 0;
}

/*
1 - 8  1 nr contine pe 9
2 - 72  18 nr contine pe 9
3 - 648  252 nr contine pe 9
*/
