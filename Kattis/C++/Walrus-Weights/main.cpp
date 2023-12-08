#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 n;
  cin >> n;

  vector<i64> v(n);

  for (auto &x : v) {
    cin >> x;
  }

  vector<bool> w(1200);
  for (auto &x : v) {
    for (i64 j = 1200 - 1; j >= 0; j--) {
      if (w[j] == true and j + x < 1200) {
        w[j + x] = true;
      }
    }

    w[x] = true;
  }

  i64 sol_upper = 1201;
  for (i64 i = 1000; i < 1200; i++) {
    if (w[i] == true) {
      sol_upper = i;
      break;
    }
  }

  i64 sol_lower = -1;
  for (i64 i = 999; i >= 0; i--) {
    if (w[i] == true) {
      sol_lower = i;
      break;
    }
  }

  if (sol_lower == -1) {
    cout << sol_upper << endl;
  } else if (sol_upper == 1201) {
    cout << sol_lower << endl;
  } else {
    if (1000 - sol_lower == sol_upper - 1000) {
      cout << sol_upper << endl;
    } else {
      if (1000 - sol_lower < sol_upper - 1000) {
        cout << sol_lower << endl;
      } else {
        cout << sol_upper << endl;
      }
    }
  }

  return 0;
}
