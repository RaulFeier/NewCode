#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void collatz(i64 n, i64 steps, map<i64, i64> &m) {
  m[steps] = n;

  if (n == 1) {
    return;
  }

  if (n % 2 == 1) {
    collatz(n * 3 + 1, ++steps, m);
  } else {
    collatz(n / 2, ++steps, m);
  }
}

int main() {
  i64 n, m;

  while (true) {
    cin >> n >> m;
    if (n == 0 and m == 0)
      break;

    map<i64, i64> m1;
    map<i64, i64> m2;

    i64 steps = 0;

    collatz(n, steps, m1);

    steps = 0;

    collatz(m, steps, m2);

    i64 ans = 0;
    i64 sol = 0;
    i64 ans1 = 0;

    bool ok = false;

    for (auto &c : m1) {
      for (auto &c2 : m2) {
        if (c.second == c2.second) {
          ans = c.first;
          ans1 = c2.first;
          sol = c.second;
          ok = true;
          break;
        }
      }
      if (ok) {
        break;
      }
    }

    cout << n << " needs " << ans << " steps, " << m << " needs " << ans1
         << " steps, they meet at " << sol << endl;
  }
  return 0;
}
