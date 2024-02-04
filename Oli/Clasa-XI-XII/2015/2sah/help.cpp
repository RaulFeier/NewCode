#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const i64 MODULO = 1e9 + 7;

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

void solve1() {
  i64 n, k;
  cin >> n >> k;

  cout << exp(3, k - 1) << endl;
}

void solve2() {
  i64 n, k;
  cin >> n >> k;

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

  char c;
  cin >> c;

  if (c == '1') {
    i64 n, k;
    cin >> n >> k;

    cout << exp(3, k - 1) << endl;
  } else {
    i64 n, k;
    cin >> n >> k;
    if (k > n + 1) {
      cout << 0 << endl;
    } else {
      cout << 2 << endl;
    }
  }

  return 0;
}