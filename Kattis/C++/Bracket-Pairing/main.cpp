#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector<vector<i64>> dp;
string ans;

i64 count(i64 l, i64 r) {
  if (ans[l] == '(' && ans[r] == ')')
    return 1;
  if (ans[l] == '[' && ans[r] == ']')
    return 1;
  if (ans[l] == '{' && ans[r] == '}')
    return 1;
  if (ans[l] == '<' && ans[r] == '>')
    return 1;

  switch (ans[r]) {
  case '(':
  case '[':
  case '{':
  case '<':
    return 0;
  }

  switch (ans[l]) {
  case ')':
  case ']':
  case '}':
  case '>':
    return 0;
  }

  if (ans[l] == '?' && ans[r] == '?')
    return 4;
  if (ans[l] == '?' || ans[r] == '?')
    return 1;
  return 0;
}

i64 solve(i64 l, i64 r) {
  if (l >= r) {
    return 1;
  }
  if (dp[l][r] >= 0) {
    return dp[l][r];
  }

  i64 res = 0;

  for (i64 i = l + 1; i <= r; i += 2) {
    res += count(l, i) * solve(l + 1, i - 1) * solve(i + 1, r);
  }

  return dp[l][r] = res;
}

int main() {
  cin >> ans;

  dp.assign(ans.size(), vector<i64>(ans.size(), -1));

  cout << solve(0, ans.size() - 1) << endl;

  return 0;
}