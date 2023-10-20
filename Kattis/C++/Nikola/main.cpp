#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 n;

vector<vector<i64>> dp(1000, vector<i64>(1000, 0));

i64 solve(vector<i64> &cost, i64 pos, i64 step) {
  if (pos >= n or pos < 0) {
    return 1e18;
  }

  if (pos == n - 1) {
    return cost[pos];
  }

  if (dp[pos][step] != 0) {
    return dp[pos][step];
  }

  return dp[pos][step] = cost[pos] + min(solve(cost, pos + step + 1, step + 1),
                                         solve(cost, pos - step, step));
}

int main() {
  cin >> n;

  vector<i64> cost(n);

  for (auto &x : cost) {
    cin >> x;
  }

  cout << solve(cost, 1, 1) << endl;

  return 0;
}
