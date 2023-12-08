#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    string s;
    cin >> s;

    vector<pair<char, int>> upr, lwr;
    for (int i = 0; i < s.length(); i++) {
      char e = s[i];

      if (e == 'b') {
        if (!lwr.empty()) {
          lwr.pop_back();
        }
        continue;
      }
      if (e == 'B') {
        if (!upr.empty()) {
          upr.pop_back();
        }
        continue;
      }

      if (isupper(e)) {
        upr.push_back({e, i});
      } else {
        lwr.push_back({e, i});
      }
    }

    set<pair<int, char>> st;
    for (auto e : upr) {
      st.insert({e.second, e.first});
    }
    for (auto e : lwr) {
      st.insert({e.second, e.first});
    }

    for (auto e : st) {
      cout << e.second;
    }
    cout << endl;
  }

  return 0;
}