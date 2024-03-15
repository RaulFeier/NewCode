#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

vector<int> cost;
vector<int> delegates;

int min_cost(int u, int c, int f) { return (c + f + u) / 2 - c + 1; }

int solve(int pos, int d_won, int d_left, int total_d, int already_won) {
  int rem = total_d - already_won - d_won;

  if (rem < already_won + d_won) {
    return 0; // we won
  }

  if (pos == delegates.size()) {
    return 1e9; // we cant win
  }

  if (dp[pos][d_won] != -1) {
    return dp[pos][d_won];
  }

  int ret1 = solve(
      pos + 1, d_won + delegates[pos], d_left - delegates[pos], total_d,
      already_won); // we take the delegates to see the minimum cost if we win
  int ret2 = solve(pos + 1, d_won, d_left - delegates[pos], total_d,
                   already_won); // we dont take the delegates to see the
                                 // minimum cost if we win

  return dp[pos][d_won] =
             min(ret1 + cost[pos],
                 ret2); // we compare the costs and take the minimum one
}

int main() {
  int n;
  cin >> n;

  int nr_of_d = 0;
  int total_d = 0;
  int already_won = 0;
  int convinced = 0;

  for (int i = 0; i < n; i++) {
    int d, c, f, u;
    cin >> d >> c >> f >> u;

    total_d += d;

    int diff = f - c;
    if (diff >= u) {
      continue; // we cannot win
    }

    if (-diff > u) {
      already_won += d;
      continue;
    }

    cost.push_back(min_cost(u, c, f)); // we search for the minimum cost to win
    delegates.push_back(d);
    convinced += d;
  }

  dp.assign(delegates.size(), vector<int>(convinced, -1));

  int minim = solve(0, 0, convinced, total_d, already_won);
  if (minim == 1e9) {
    cout << "impossible" << endl;
  } else {
    cout << minim << endl;
  }

  return 0;
}