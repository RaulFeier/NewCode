#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n * m);

  int eep = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      v[i][j] = eep;
      eep++;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}