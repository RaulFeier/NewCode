#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<vector<int>> vv;

  vv.resize(2);

  vv[0].push_back(1);
  vv[1].push_back(2);

  for (int i = 0; i < 1; i++) {
    for (int j = 0; j < 1; j++) {
      cout << vv[i][j] << " ";
    }
    cout << endl;
  }
}