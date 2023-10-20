#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using vi64 = vector<i64>;

vector<vector<i64>> solution;
bool duplicate = false;

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

bool solved(vector<vi64> &v) {
  for (i64 i = 0; i < 9; i++) {
    for (i64 j = 0; j < 9; j++) {
      if (v[i][j] == 0) {
        return false;
      }
    }
  }

  return true;
}

void solve(vector<vi64> &v) {
  if (solved(v)) {
    if (solution.size() == 0) {
      solution = v;
      return;
    } else {
      duplicate = true;
      return;
    }
  }

  i64 mini = 10;
  i64 minx = -1;
  i64 miny = -1;
  vi64 minioptions;

  for (i64 i = 0; i < 9; i++) {
    for (i64 j = 0; j < 9; j++) {
      if (v[i][j] != 0) {
        continue;
      }
      vi64 options;
      for (i64 k = 1; k <= 9; k++) {
        if (isSafe(v, i, j, k)) {
          options.push_back(k);
        }
      }
      if (options.size() < mini) {
        mini = options.size();
        minioptions = options;
        minx = i;
        miny = j;
      }
    }
  }

  if (mini == 0) {
    return;
  }
  assert(mini != 10);

  for (i64 i = 0; i < minioptions.size(); i++) {
    v[minx][miny] = minioptions[i];
    solve(v);
    if (duplicate)
      return;
    v[minx][miny] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // ifstream cin{"input.txt"};
  // ofstream cout{"output.txt"};

  i64 a;

  while (cin >> a) {
    vector<vector<i64>> v(9, vector<i64>(9));

    v[0][0] = a;

    for (i64 i = 0; i < 9; i++) {
      for (i64 j = 0; j < 9; j++) {
        if (i == 0 and j == 0) {
          continue;
        } else {
          cin >> v[i][j];
        }
      }
    }

    solution.clear();
    if (!check(v)) {
      cout << "Find another job" << endl << endl;
      continue;
    }

    duplicate = false;
    solve(v);

    if (duplicate) {
      cout << "Non-unique" << endl << endl;
      continue;
    }
    if (solution.size() == 0) {
      cout << "Find another job" << endl << endl;
      continue;
    }

    for (i64 i = 0; i < 9; i++) {
      for (i64 j = 0; j < 9; j++) {
        cout << solution[i][j] << " ";
      }
      cout << endl;
    }

    cout << endl;
  }

  return 0;
}