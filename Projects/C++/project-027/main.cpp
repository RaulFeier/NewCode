#include <bits/stdc++.h>

using namespace std;

int main() {
  int ann;
  cin >> ann;

  ann = ann * 12; // 12 months

  int a = 0;
  for (int i = 0; i < 12; i++) {
    if (ann % 26 == 2) {
      a = 1;
    }
    ann = ann - 1;
  }

  if (a == 1) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}