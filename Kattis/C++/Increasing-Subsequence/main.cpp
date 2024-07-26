#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N;

  while (cin >> N) {
    if (N == 0)
      break;

    vector<int> v(N);

    set<int> s;
    for (auto &c : v) {
      cin >> c;
      s.insert(c);
    }

    map<int, int> m;
    int index = 0;
    vector<int> V(N);

    for (auto &c : s) {
      m[c] = index;
      V[index] = c;
      index++;
    }

    int mx = 0;
    vector<int> dp(N, 0);

    for (int i = 0; i < N; i++) {
      int val = m[v[i]];
      for (int j = val - 1; j >= 0; j--) {
        dp[val] = max(dp[j] + 1, dp[val]);
      }

      if (dp[val] == 0)
        dp[val] = 1;

      mx = max(mx, dp[val]);
    }

    vector<int> f;
    for (int i = 0; i < N; i++) {
      if (dp[i] == mx) {
        f.push_back(i);
      }
    }

    vector<vector<int>> sub;

    for (auto &c : f) {
      int aux_mx = mx;
      vector<int> sol;
      index = c;

      while (index >= 0) {
        if (dp[index] == aux_mx) {
          int val = 1e9;
          while (index >= 0 and dp[index] == aux_mx) {
            val = min(val, V[index]);
            index--;
          }
          sol.push_back(val);
          aux_mx--;
        } else {
          index--;
        }
      }

      reverse(sol.begin(), sol.end());
      sub.push_back(sol);
    }

    sort(sub.begin(), sub.end());

    cout << sub[0].size() << " ";
    for (auto &c : sub[0]) {
      cout << c << " ";
    }
    cout << '\n';
  }

  return 0;
}