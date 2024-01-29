#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  ifstream cin{"shell.in"};
  ofstream cout{"shell.out"};

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 n;
  cin >> n;

  vector<pair<i64, i64>> p(n);
  vector<i64> g(n);
  for (i64 i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second >> g[i];
  }

  i64 res = -1;
  for (i64 ttt = 1; ttt <= 3; ttt++) {
    vector<bool> b(4, false);
    b[ttt] = true;

    i64 t = 0;
    for (i64 i = 0; i < n; i++) {
      auto crt = p[i];
      if (b[crt.first] == false and b[crt.second] == true) {
        b[crt.first] = true;
        b[crt.second] = false;
      } else if (b[crt.first] == true and b[crt.second] == false) {
        b[crt.first] = false;
        b[crt.second] = true;
      }

      if (b[g[i]]) {
        t++;
      }
    }

    res = max(res, t);
  }

  cout << res << endl;

  return 0;
}