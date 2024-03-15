#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

vector<vector<vector<i64>>> memo;

i64 solve(i64 index, i64 nr_left, i64 sum, vector<i64> &bag) {
  if (nr_left == 0 and sum == 0)
    return 1; // found a subset of set bag that have the sum equal to sum
  if (nr_left == 0 or sum < 0)
    return 0; // the sum is higher than the sum

  if (index == bag.size())
    return 0; // not enough elements

  if (memo[index][nr_left][sum] != -1)
    return memo[index][nr_left][sum];

  return memo[index][nr_left][sum] =
             solve(index + 1, nr_left, sum, bag) +
             solve(index + 1, nr_left - 1, sum - bag[index], bag);
}

vector<vector<i64>> dp;

i64 comb(i64 n, i64 k) {
  if (n < k)
    return 0;
  if (k == n or k == 0)
    return 1;

  if (dp[n][k] != -1) {
    return dp[n][k];
  }

  return dp[n][k] = comb(n - 1, k - 1) + comb(n - 1, k);
}

int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);

  i64 nr_g;
  cin >> nr_g;

  dp.assign(31, vector<i64>(31, -1));

  for (int tc = 1; tc <= nr_g; tc++) {
    i64 n;
    cin >> n;

    vector<i64> bag(n);
    for (int i = 0; i < n; i++) {
      cin >> bag[i];
    }

    int m, t;
    cin >> m >> t;
    memo.assign(bag.size(), vector<vector<i64>>(m + 1, vector<i64>(10000, -1)));

    int a = solve(0, m, t, bag);
    int b = comb(n, m);

    cout << "Game " << tc << " -- " << a << " : " << b - a << '\n';
  }

  return 0;
}

/*
1 2 2 2 2 2 2 2 2 2
3 6

3C10
*/