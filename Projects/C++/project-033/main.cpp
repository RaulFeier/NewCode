#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  while (cin >> a >> b >> c) {
    if (a == 0 && b == 0 && c == 0) {
      return 0;
    } else {
      if (a > b) {
        int i = a;
        a = b; // swap la fiecare
        b = i;
      }
      if (b > c) {
        int i = b;
        b = c;
        c = i;
      }
      if (a > c) {
        int i = a;
        a = c;
        c = i;
      }
      if (c * c == (a * a) + (b * b)) {
        cout << "right" << endl;
      } else {
        cout << "wrong" << endl;
      }
    }
  }
}