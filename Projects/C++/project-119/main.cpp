#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int a;
    int p_a = 1;

    int total = 0;
    while (true) {
      cin >> a;
      if (a == 0) {
        break;
      }
      if (p_a == a) {
        p_a = a;
        continue;
      } else if (a <= 2 * p_a) {
        p_a = a;
        continue;
      } else {
        total += a - 2 * p_a;
        p_a = a;
      }
    }

    cout << total << endl;
  }

  return 0;
}

/*
1 28 72
1 2  3

1 - 1
2 - [1,2] 28 - 2 = 26;
3 - [28, 56] 72 - 56 = 16;
total = 26 + 16 = 42
*/