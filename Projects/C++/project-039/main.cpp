#include <bits/stdc++.h>

using namespace std;

int main() {

  // alegeti pb
  int pb;
  cin >> pb;

  if (pb == 1) {
    char c[40];

    cin.getline(c, 40);

    for (int i = 0; i < strlen(c); i++) {
      for (int j = 0; j < strlen(c); j++) {
        if (i == j) {
          continue;
        } else {
          cout << c[j];
        }
      }
      cout << endl;
    }
  } else if (pb == 2) {
    char c[100];

    cin.getline(c, 100);

    for (int i = 0; i < strlen(c); i++) {
      if (c[i] == 'a') {
        c[i] = 'b';
      } else if (c[i] == 'e') {
        c[i] = 'f';
      } else if (c[i] == 'i') {
        c[i] = 'j';
      } else if (c[i] == 'o') {
        c[i] = 'p';
      } else if (c[i] == 'u') {
        c[i] = 'v';
      }
    }

    cout << c << endl;
  }

  return 0;
}