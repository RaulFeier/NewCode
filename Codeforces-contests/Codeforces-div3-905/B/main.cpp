#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
using i64 = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n, k;
    cin >> n >> k;

    string ans;
    cin >> ans;

    map<char, i64> m;
    for (auto &c : ans) {
      m[c]++;
    }

    i64 total = 0;
    for (auto &c : m) {
      if (c.second % 2 == 1) {
        total++;
      }
    }

    if (total > k + 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }

  return 0;
}