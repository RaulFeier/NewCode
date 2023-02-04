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
#define endl '\n'

using byte = int8_t;
using i64 = int64_t;

using d64 = long double;

int main() {
  //   ifstream cin{"input.txt"};
  //   ofstream cout{"output.txt"};

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 t;
    cin >> t;

    vector<vector<string>> v(3, vector<string>(t));
    map<string, i64> m;
    for (i64 i = 0; i < t; i++) {
      cin >> v[0][i];
      m[v[0][i]]++;
    }

    for (i64 i = 0; i < t; i++) {
      cin >> v[1][i];
      m[v[1][i]]++;
    }

    for (i64 i = 0; i < t; i++) {
      cin >> v[2][i];
      m[v[2][i]]++;
    }

    i64 a = 0, b = 0, c = 0;
    for (i64 i = 0; i < t; i++) {
      if (m[v[0][i]] == 1) {
        a += 3;
      } else if (m[v[0][i]] == 2) {
        a += 1;
      }
      if (m[v[1][i]] == 1) {
        b += 3;
      } else if (m[v[1][i]] == 2) {
        b += 1;
      }
      if (m[v[2][i]] == 1) {
        c += 3;
      } else if (m[v[2][i]] == 2) {
        c += 1;
      }
    }

    cout << a << " " << b << " " << c << endl;
  }

  return 0;
}