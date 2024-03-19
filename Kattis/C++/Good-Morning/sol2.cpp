#include <bits/stdc++.h>

using namespace std;
int const INF = 1e9;

vector<int> adjlist[10];
vector<vector<int>> dp;

int sol(int n, int pos, int cur_val) {
  if (cur_val >= n) {
    return cur_val;
  }

  if (cur_val == 0 and pos == 0) {
    return 0;
  }

  int best = cur_val;
  int sm = abs(cur_val - n);

  for (auto &c : adjlist[pos]) {
    int val;
    if (c == pos) {
      if (dp[c][cur_val * 10 + c] != -1) {
        val = dp[c][cur_val * 10 + c];
      } else {
        val = sol(n, c, cur_val * 10 + c);
      }
    } else {
      if (dp[c][cur_val] != -1) {
        val = dp[c][cur_val];
      } else {
        val = sol(n, c, cur_val);
      }
    }

    int diff = abs(val - n);
    if (diff < sm) {
      sm = diff;
      best = val;
    }
  }

  return dp[pos][best] = best;
}

int main() {
  adjlist[0] = {0};
  adjlist[1] = {1, 4, 2};
  adjlist[2] = {2, 3, 5};
  adjlist[3] = {3, 6};
  adjlist[4] = {4, 5, 7};
  adjlist[5] = {5, 6, 8};
  adjlist[6] = {6, 9};
  adjlist[7] = {7, 8};
  adjlist[8] = {8, 0, 9};
  adjlist[9] = {9};

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;
    dp.assign(10, vector<int>(201, -1));

    cout << sol(n, 1, 0) << endl;
  }

  return 0;
}