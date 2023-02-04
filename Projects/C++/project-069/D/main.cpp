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
    i64 k;
    cin >> k;

    string line;
    cin >> line;

    vector<i64> v;

    for (i64 i = 0; i < k; i++) {
      i64 eep = 0;
      string cline = line;
      for (i64 j = 0; j < k / 2; j++) {
        if (line[j] == 'L') {
          cline[j] = 'R';
          eep++;
        }
        if (eep == i + 1) {
          break;
        }
        if (line[k - j - 1] == 'R') {
          cline[k - j - 1] = 'L';
          eep++;
        }
        if (eep == i + 1) {
          break;
        }
      }
      i64 total = 0;
      for (i64 x = 0; x < cline.size(); x++) {
        if (cline[x] == 'R') {
          total += cline.size() - (x + 1);
        } else {
          total += x;
        }
      }
      cout << total << " ";
    }
    cout << endl;
  }

  return 0;
}