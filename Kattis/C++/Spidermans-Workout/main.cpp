#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

i64 n;
i64 ans;
string best;

void solve(vector<i64> &v, i64 pos, i64 height, i64 mxh, string &sol,
           vector<vector<i64>> &dp) {
  if (height < 0 or height > 1000) {
    return;
  }

  if (dp[pos][height] <= mxh) {
    return;
  }

  dp[pos][height] = mxh;

  if (pos == v.size()) {
    if (height == 0 and mxh < ans) {
      ans = mxh;
      best = sol;
      // save sol;
    }
    return;
  }

  if (height - v[pos] >= 0) {
    sol.push_back('D');
    solve(v, pos + 1, height - v[pos], mxh, sol, dp);
    sol.pop_back();
  }

  if (height + v[pos] < ans) {
    sol.push_back('U');
    solve(v, pos + 1, height + v[pos], max(height + v[pos], mxh), sol, dp);
    sol.pop_back();
  }
}

void read() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  vector<i64> v(n);

  for (auto &x : v) {
    cin >> x;
  }

  string sol;
  ans = 1e9;
  vector<vector<i64>> dp(1000, vector<i64>(1000, 1e9));

  solve(v, 0, 0, 0, sol, dp);

  if (ans == 1e9) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << best << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  i64 tc;
  cin >> tc;

  while (tc--) {
    read();
  }

  return 0;
}