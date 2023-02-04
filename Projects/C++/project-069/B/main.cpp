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
    i64 l;
    cin >> l;
    string e1, e2;
    cin >> e1;
    cin >> e2;

    for (auto &x : e1) {
      if (x == 'G') {
        x = 'C';
      } else if (x == 'B') {
        x = 'C';
      }
    }

    for (auto &x : e2) {
      if (x == 'G') {
        x = 'C';
      } else if (x == 'B') {
        x = 'C';
      }
    }

    bool eep = false;
    for (i64 i = 0; i < l; i++) {
      if (e1[i] != e2[i]) {
        eep = true;
        break;
      }
    }

    if (eep) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }

  return 0;
}