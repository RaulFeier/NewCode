#include <bits/stdc++.h>

using namespace std;
using i16 = short;

int main() {
  ifstream cin{"joc13.in"};
  ofstream cout{"joc13.out"};

  int n, k;
  cin >> n >> k;

  vector<vector<int>> v(2, vector<int>(n));
  vector<vector<int>> prefix_sum(2, vector<int>(n));

  for (i16 i = 0; i < 2; i++) {
    for (i16 j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }

  prefix_sum[0][0] = v[0][0];

  for (i16 j = 1; j < n; j++) {
    for (i16 i = 0; i < 2; i++) {
      int s = v[i][j];
      prefix_sum[i][j] = -9999;

      for (i16 index = j - 1; index >= 0 and j - index < k; index--) {
        s += v[i][index];
        prefix_sum[i][j] = max(prefix_sum[i][j], s + prefix_sum[1 - i][index]);
      }
    }
  }

  prefix_sum[1][n - 1] =
      max(prefix_sum[1][n - 1], v[1][n - 1] + prefix_sum[0][n - 1]);
  cout << prefix_sum[1][n - 1] << endl;

  return 0;
}