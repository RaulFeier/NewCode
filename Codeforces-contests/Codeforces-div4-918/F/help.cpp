/*    ___                       ___           ___
     /\__\          ___        /\  \         /\__\
    /::|  |        /\  \      /::\  \       /:/  /
   /:|:|  |        \:\  \    /:/\ \  \     /:/  /
  /:/|:|__|__      /::\__\  _\:\~\ \  \   /:/  /  ___
 /:/ |::::\__\  __/:/\/__/ /\ \:\ \ \__\ /:/__/  /\__\
 \/__/~~/:/  / /\/:/  /    \:\ \:\ \/__/ \:\  \ /:/  /
       /:/  /  \::/__/      \:\ \:\__\    \:\  /:/  /
      /:/  /    \:\__\       \:\/:/  /     \:\/:/  /
     /:/  /      \/__/        \::/  /       \::/  /
     \/__/                     \/__/         \/__/
*/

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    map<i64, i64> m;

    for (i64 i = 0; i < n; i++) {
      i64 a, b;
      cin >> a >> b;
      m[a] = b;
    }

    i64 total = 0;

    for (auto i = m.begin(); i != m.end(); i++) {
      for (auto j = i; j != m.end(); j++) {
        if (i->second > j->second and i->first != j->first) {
          total++;
        }
      }
    }

    cout << total << '\n';
  }

  return 0;
}

/*

*/