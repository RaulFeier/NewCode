#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int r, c;
    cin >> r >> c;
    char m[r][c];
    cout << "Test " << i + 1 << endl;
    for (int j = 0; j < r; j++) {
      for (int k = 0; k < c; k++) {
        cin >> m[j][k];
      }
    }

    for (int j = r - 1; j >= 0; j--) {
      for (int k = c - 1; k >= 0; k--) {
        cout << m[j][k];
      }
      cout << endl;
    }
  }
}