#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<pair<int, int>> eep = {{1, 2}, {3, 4}, {5, 2}};
  pair<int, int> o = {1, 1};

  auto it = lower_bound(eep.begin(), eep.end(), o);

  cout << it - eep.begin() << endl;

  return 0;
}