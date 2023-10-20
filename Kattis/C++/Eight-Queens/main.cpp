#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<char>> &v, int row, int col) {
  for (int i = 0; i < 8; i++) {
    if (v[row][i] == '*' and i != col) {
      return false;
    }
  }

  for (int i = 0; i < 8; i++) {
    if (v[i][col] == '*' and i != row) {
      return false;
    }
  }

  int i = row - 1;
  int j = col - 1;
  while (i >= 0) {
    if (v[i][j] == '*') {
      return false;
    } else {
      i--;
      j--;
    }
  }

  i = row + 1;
  j = col + 1;

  while (i < 8) {
    if (v[i][j] == '*') {
      return false;
    } else {
      i++;
      j++;
    }
  }

  i = row + 1;
  j = col - 1;

  while (i < 8) {
    if (v[i][j] == '*') {
      return false;
    } else {
      i++;
      j--;
    }
  }

  i = row - 1;
  j = col + 1;

  while (i >= 0) {
    if (v[i][j] == '*') {
      return false;
    } else {
      i--;
      j++;
    }
  }

  return true;
}

bool solve(vector<vector<char>> &v) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (v[i][j] == '*') {
        if (!check(v, i, j)) {
          return false;
        }
      }
    }
  }

  return true;
}

int main() {
  vector<vector<char>> v(8, vector<char>(8));

  int t = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> v[i][j];
      if (v[i][j] == '*') {
        t++;
      }
    }
  }

  if (solve(v) and t == 8) {
    cout << "valid" << endl;
  } else {
    cout << "invalid" << endl;
  }

  return 0;
}