#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

i64 greedy_algo(i64 value, vector<i64> &money) {
  i64 res = 0;
  while (value != 0) {
    i64 crt;
    for (int i = 0; i < money.size(); i++) {
      if (money[i] > value) {
        break;
      } else {
        crt = money[i];
      }
    }

    while (value - crt >= 0) {
      value -= crt;
      res++;
    }
  }

  return res;
}

i64 solve(i64 value, vector<i64> &money, int dp[]) {
  if (dp[value] != 0)
    return dp[value];

  if (value == 0)
    return 0;

  i64 res = 1e9;
  for (i64 i = 0; i < money.size(); i++) {
    i64 sub_tree;
    if (value >= money[i]) {
      sub_tree = solve(value - money[i], money, dp) + 1;
      res = min(res, sub_tree);
    }
  }
  return dp[value] = res;
}

int main() {
  i64 n;
  cin >> n;

  vector<i64> money(n);

  for (auto &c : money) {
    cin >> c;
  }

  i64 value = money[n - 1] + money[n - 2] - 1;

  bool eep = true;
  for (int i = 1; i <= value; i++) {
    int dp[i + 1];
    if (greedy_algo(i, money) > solve(i, money, dp)) {
      eep = false;
      cout << i << endl;
      break;
    }
  }

  if (!eep) {
    cout << "non-canonical";
  } else {
    cout << "canonical";
  }

  return 0;
}