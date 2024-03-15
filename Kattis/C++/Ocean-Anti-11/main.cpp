#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
const i64 MOD = 1e9 + 7;

vector<int> f;

int fib(int n) {
  if (f[n]) {
    return f[n];
  } else if (n == 0 or n == 1) {
    return 1;
  }

  int res = fib(n - 1) + fib(n - 2);
  return f[n] = res;
}

int main() {
  f.assign(10000, 0);

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;
    n--;

    cout << fib(n + 1) % MOD << endl;
  }

  return 0;
}

/*
0 0
1 1
1 2
2 3
3 4
5 5
8 6
13 7
21 8
34 9
55 10
89 11
144 12
*/