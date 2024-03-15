#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

vector<vector<int>> dp;

int solve(vector<pair<int, int>> &v, int pos, int cantity) {
  if (pos == v.size() or cantity == 0)
    return 0;

  if (dp[pos][cantity] != -1) {
    return dp[pos][cantity];
  }

  if (cantity < v[pos].second) {
    return dp[pos][cantity] = solve(v, pos + 1, cantity);
  }

  return dp[pos][cantity] =
             max(solve(v, pos + 1, cantity),
                 v[pos].first + solve(v, pos + 1, cantity - v[pos].second));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int c, n;
  while (cin >> c >> n) {
    dp.assign(2002, vector<int>(2002, -1));
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) {
      cin >> v[i].first >> v[i].second;
    }

    vector<int> f;

    for (int i = 0; i < n; i++) {
      if (solve(v, i, c) == solve(v, i + 1, c)) {
        continue;
      } else {
        f.push_back(i);
        c -= v[i].second;
      }
    }

    cout << f.size() << endl;

    if (f.size() > 0) {
      for (auto &c : f) {
        cout << c << " ";
      }
      cout << endl;
    }
  }

  return 0;
}