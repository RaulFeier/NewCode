#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector<int> lsolve(vector<int> rand) { return rand; }

void left(vector<vector<i64>> &v) {
  vector<int> rand;
  for (i64 t = 0; t < 4; t++) {
    for (i64 i = t; i < t + 1; i++) {
      for (i64 j = 0; j < 4; j++) {
        rand.push_back(v[i][j]);
        rand = lsolve(rand);
        // eventual poti sa faci o functie de print si sa printezi numa randu si
        // sa nu mai inlocuiesti in matrice randu ca consumi timp, cum ti se
        // pare tie mai ok
      }
    }
  }
}

vector<int> usolve(vector<int> rand) { return rand; }

void up(vector<vector<i64>> &v) {}

vector<int> rsolve(vector<int> rand) { return rand; }

void right(vector<vector<i64>> &v) {}

vector<int> dsolve(vector<int> rand) { return rand; }

void down(vector<vector<i64>> &v) {}

int main() {
  vector<vector<i64>> grid(4, vector<i64>(4));

  for (i64 i = 0; i < 4; i++) {
    for (i64 j = 0; j < 4; j++) {
      cin >> grid[i][j];
    }
  }

  i64 pos;
  cin >> pos;

  if (pos == 0) {
    left(grid);
  } else if (pos == 1) {
    up(grid);
  } else if (pos == 2) {
    right(grid);
  } else {
    down(grid);
  }
}