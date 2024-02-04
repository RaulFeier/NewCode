#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 sieve(i64 n, i64 k) {
  i64 cnt = 0;
  vector<bool> bs(n + 1, true);

  for (i64 i = 2; i <= n; i++) {
    if (bs[i]) {
      for (i64 j = i; j <= n; j += i) {
        if (bs[j]) {
          bs[j] = 0;
          cnt++;
          if (cnt == k) {
            return j;
          }
        }
      }
    }
  }
}

int main() {

  i64 n, k;
  cin >> n >> k;

  cout << sieve(n, k) << endl;

  return 0;
}

/*
7 3
0 1 2 4 6 3

15 12
2 4 6 8 10 12 14
*/
