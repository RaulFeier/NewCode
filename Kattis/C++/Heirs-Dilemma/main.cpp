#include <bits/stdc++.h>

using namespace std;

int main() {
  int l, r;
  cin >> l >> r;

  int cnt = 0;
  for (int i = l; i <= r; i++) {
    int eep = i;
    map<int, int> m;
    bool check = false;

    while (eep != 0) {
      if (eep % 10 == 0) {
        check = true;
        break;
      }
      if (m[eep % 10] == 1) {
        check = true;
        break;
      } else {
        m[eep % 10]++;
        eep /= 10;
      }
    }

    if (check) {
      continue;
    }

    check = false;
    for (auto x : m) {
      if (x.first == 0) {
        continue;
      }

      if (i % x.first != 0) {
        check = true;
        break;
      }
    }

    if (check) {
      continue;
    }

    cnt++;
  }

  cout << cnt << endl;

  return 0;
}
