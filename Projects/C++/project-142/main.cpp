#include <bits/stdc++.h>

using namespace std;

int main() {
  char c[21];

  char m1[4] = {'B', 'F', 'P', 'V'};
  char m2[8] = {'C', 'G', 'J', 'K', 'Q', 'S', 'X', 'Z'};

  while (cin.getline(c, 21)) {
    int before = -1;

    for (int i = 0; i < strlen(c); i++) {
      bool chaged = false;

      // case for 1
      for (int j = 0; j < 4; j++) {
        if (c[i] == m1[j]) {
          if (before != 1) {
            cout << 1;
            before = 1;
            chaged = true;
          }
        }
      }

      // case for 2
      for (int j = 0; j < 8; j++) {
        if (c[i] == m2[j]) {
          if (before != 2) {
            cout << 2;
            before = 2;
            chaged = true;
          }
        }
      }

      // case for 3
      if (c[i] == 'D' or c[i] == 'T') {
        if (before != 3) {
          cout << 3;
          before = 3;
          chaged = true;
        }
      }

      // case for 4
      if (c[i] == 'L') {
        if (before != 4) {
          cout << 4;
          before = 4;
          chaged = true;
        }
      }

      // case for 5
      if (c[i] == 'M' or c[i] == 'N') {
        if (before != 5) {
          cout << 5;
          before = 5;
          chaged = true;
        }
      }

      // case for 6
      if (c[i] == 'R') {
        if (before != 6) {
          cout << 6;
          before = 6;
          chaged = true;
        }
      }

      if (!chaged) {
        before = -1;
      }
    }

    cout << endl;
  }

  return 0;
}
