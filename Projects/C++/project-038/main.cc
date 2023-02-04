#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

void solve(int n, int pos, vector<i64> sol) {
  if (pos == n) {
    for (auto e : sol) {
      cout << e << " ";
    }
    cout << endl;
    return;
  }
  for (i64 i = 1; i <= n; i++) {
    bool found = false;
    for (auto e : sol) {
      if (e == i) {
        found = true;
        break;
      }
    }
    if (!found) {
      sol.push_back(i);
      solve(n, pos + 1, sol);
      sol.pop_back();
    }
  }
}

int main() {
  i64 n;
  cin >> n;
  vector<i64> sol;
  solve(n, 0, sol);
  return 0;
}