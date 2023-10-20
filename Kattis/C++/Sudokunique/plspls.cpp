#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using vi64 = vector<i64>;
#define endl '\n'

bool isSafe(vector<vi64> &v, i64 row, i64 col, i64 num) {
  for (i64 i = 0; i < 9; i++) {
    if (v[row][i] == num) {
      return false;
    }
  }

  for (i64 i = 0; i < 9; i++) {
    if (v[i][col] == num) {
      return false;
    }
  }

  i64 startRow = row - row % 3;
  i64 startCol = col - col % 3;

  for (i64 i = 0; i < 3; i++) {
    for (i64 j = 0; j < 3; j++) {
      if (v[i + startRow][j + startCol] == num) {
        return false;
      }
    }
  }

  return true;
}

bool solve(vector<vi64> &v, i64 row, i64 col) {
  if (row == 9 - 1 and col == 9) {
    return true;
  }

  if (col == 9) {
    row++;
    col = 0;
  }

  if (v[row][col] > 0) {
    return solve(v, row, col + 1);
  }

  for (i64 i = 1; i <= 9; i++) {
    if (isSafe(v, row, col, i)) {
      v[row][col] = i;

      if (solve(v, row, col + 1)) {
        return true;
      }
    }
    v[row][col] = 0;
  }

  return false;
}

bool isSafeStart(vector<vi64> &v, i64 row, i64 col, i64 num) {
  for (i64 i = 0; i < 9; i++) {
    if (i == col) {
      continue;
    } else {
      if (v[row][i] == num) {
        return false;
      }
    }
  }

  for (i64 i = 0; i < 9; i++) {
    if (i == row) {
      continue;
    } else {
      if (v[i][col] == num) {
        return false;
      }
    }
  }

  i64 startRow = row - row % 3;
  i64 startCol = col - col % 3;

  for (i64 i = 0; i < 3; i++) {
    for (i64 j = 0; j < 3; j++) {
      if (startRow + i == row and startCol + j == col) {
        continue;
      }
      if (v[i + startRow][j + startCol] == num) {
        return false;
      }
    }
  }

  return true;
}

bool check(vector<vi64> &v) {
  i64 row = 0;
  i64 col = 0;
  bool check = false;

  while (true) {
    if (v[row][col] > 0) {
      if (!isSafeStart(v, row, col, v[row][col])) {
        check = true;
        break;
      }
    }
    col++;
    if (row == 8 and col == 9) {
      break;
    }
    if (col == 9) {
      row++;
      col = 0;
    }
  }

  if (check) {
    return false;
  } else {
    return true;
  }
}

int main() {
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};

  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  i64 a;

  while (cin >> a) {
    vector<vi64> v(9, vi64(9));

    v[0][0] = a;

    pair<i64, i64> p;
    for (i64 i = 0; i < 9; i++) {
      for (i64 j = 0; j < 9; j++) {
        if (i == 0 and j == 0) {
          continue;
        } else {
          cin >> v[i][j];
        }
        if (v[i][j] == 0) {
          p.first = i;
          p.second = j;
        }
      }
    }

    vector<vi64> cv = v;
    vector<vi64> aa;

    if (check(v)) {
      i64 t = 0;

      for (i64 num = 1; num <= 9; num++) {
        if (isSafe(v, p.first, p.second, num)) {
          v[p.first][p.second] = num;
          if (solve(v, 0, 0)) {
            t++;
            aa = v;
            v = cv;
          }
        }
        if (t == 2) {
          break;
        }
      }

      if (t == 1) {
        for (i64 i = 0; i < 9; i++) {
          for (i64 j = 0; j < 9; j++) {
            cout << aa[i][j] << " ";
          }
          cout << endl;
        }
        cout << endl;
      } else if (t == 0) {
        cout << "Find another job" << endl;
        cout << endl;
      } else {
        cout << "Non-unique" << endl;
        cout << endl;
      }

    } else {
      cout << "Find another job" << endl;
      cout << endl;
    }
  }

  return 0;
}
