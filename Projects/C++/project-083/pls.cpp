#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  //   ifstream cin{"input.txt"};
  //   ofstream cout{"output.txt"};

  i64 n, h;
  cin >> n >> h;
  vector<i64> v(h + 2);

  for (i64 i = 0; i < n; i++) {
    i64 x;
    cin >> x;

    if (i % 2 == 0) {
      v[1] += 1;
      v[x + 1] -= 1;
    } else {
      v[h - x + 1] += 1;
    }
  }

  i64 res = 1e9;
  i64 nr = 0;
  i64 t = 0;

  for (i64 i = 1; i < h + 1; i++) {
    t += v[i];
    if (t == res) {
      nr++;
    } else if (t < res) {
      nr = 1;
      res = t;
    }
  }

  cout << res << " " << nr << endl;
}