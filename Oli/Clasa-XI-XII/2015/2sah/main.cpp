#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const i64 MODULO = 1e5 + 3;

i64 exp(i64 x, i64 y) {
  if (y == 0) {
    return 1;
  }
  if (y == 1) {
    return x;
  }

  if (y % 2 == 0) {
    i64 temp = exp(x, y / 2) % MODULO;
    return (temp * temp) % MODULO;
  } else {
    i64 temp = exp(x, y / 2) % MODULO;
    return (temp * temp * x) % MODULO;
  }
}

void solve1(i64 n, i64 k) {
  ofstream cout{"2sah.out"};

  cout << exp(3, k - 1) % MODULO << endl;
}

void solve2(i64 n, i64 k) {
  ofstream cout{"2sah.out"};

  if (k > n + 1) {
    cout << 0 << endl;
    return;
  }

  cout << 2 << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ifstream cin{"2sah.in"};

  char c;
  cin >> c;

  i64 n, k;
  cin >> n >> k;
  if (c == '1') {
    solve1(n, k);
  } else {
    solve2(n, k);
  }

  return 0;
}