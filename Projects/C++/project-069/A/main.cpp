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

using d6 = long double;
using d64 = long double;

int main() {
  //   ifstream cin{"input.txt"};
  //   ofstream cout{"output.txt"};

  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 l;
    cin >> l;
    string ans;
    cin >> ans;

    if (l != 5) {
      cout << "NO" << endl;
      continue;
    }

    vector<bool> v(5, false);

    for (auto &x : ans) {
      if (x == 'T') {
        v[0] = true;
      } else if (x == 'i') {
        v[1] = true;
      } else if (x == 'm') {
        v[2] = true;
      } else if (x == 'u') {
        v[3] = true;
      } else if (x == 'r') {
        v[4] = true;
      }
    }

    short eep = 0;
    for (int x = 0; x < v.size(); x++) {
      if (v[x]) {
        eep++;
      }
    }
    if (eep == 5) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}