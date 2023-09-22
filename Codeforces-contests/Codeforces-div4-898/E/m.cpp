#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

using i64 = int64_t;

i64 getWater(int h, vector<i64> &v) {
  i64 res = 0;
  for (auto e : v) {
    if (e < h) {
      res += h - e;
    }
  }

  return res;
}

int main() {
  i64 tc;
  cin >> tc;
  while (tc--) {
    i64 n, w;
    cin >> n >> w;
    vector<i64> v(n);
    i64 l = 0, r = 2e9;
    for (auto &e : v) {
      cin >> e;
    }

    while (l <= r) {
      i64 mid = l + (r - l) / 2;
      i64 water = getWater(mid, v);

      if (water > w) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    cout << l - 1 << endl;
  }

  return 0;
}