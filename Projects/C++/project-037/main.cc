#include <bits/stdc++.h>

using namespace std;

ifstream fin("Riana.in");

int main() {
  int n = 4;
  int m[4][4];

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      fin >> m[i][j];
    }
  }

  cout << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << m[j][i] << " ";
    }
    cout << endl;
  }
}