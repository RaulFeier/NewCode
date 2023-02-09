#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 a, b, c;
  cin >> a >> b >> c;

  a += b;

  i64 t = 0;

  i64 nr_total_sticle = a;
  while (true) {
    if (nr_total_sticle / c == 0) {
      break;
    } else {
      t += nr_total_sticle / c;
      i64 eep = nr_total_sticle / c;
      nr_total_sticle = (nr_total_sticle % c) + eep;
    }
  }

  cout << t << endl;
  return 0;
}