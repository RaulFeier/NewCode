#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

vector<bool> bs;
i64 _size;
i64 sol = 0;

void sieve(i64 n) {
  _size = n + 1;
  bs[0] = bs[1] = 0;

  for (i64 i = 2; i < _size; i++) {
    if (bs[i]) {
      sol++;
      for (i64 j = i * i; j < _size; j += i) {
        bs[j] = 0;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 n, q;
  cin >> n >> q;

  bs.assign(n + 1, true);

  sieve(n);

  cout << sol << endl;

  while (q--) {
    i64 x;
    cin >> x;
    if (bs[x]) {
      cout << 1 << endl;
    } else {
      cout << 0 << endl;
    }
  }

  return 0;
}