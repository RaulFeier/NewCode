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
  ifstream cin{"turnuri4.in"};
  ofstream cout{"turnuri4.out"};
  int n;
  cin >> n;

  vector<int> eep(n);

  for (int i = 0; i < n; i++) {
    cin >> eep[i];
  }

  int a;
  i64 total = 0;

  for (int tc = 0; tc < n; tc++) {
    a = eep[tc];
    eep[tc] = 0;

    for (int i = 0; i < n; i++) {
      total++;
      if (eep[i + 1] < eep[i] and i != n - 1) {
        for (int j = i + 1; j < n; j++) {
          if (eep[i] < eep[j]) {
            break;
          } else {
            total++;
          }
        }
      }
      if (eep[i - 1] < eep[i] and i != 0) {
        for (int j = i - 1; j >= 0; j--) {
          if (eep[i] < eep[j]) {
            break;
          } else {
            total++;
          }
        }
      }
    }

    cout << total << endl;
    total = 0;

    eep[tc] = a;
  }

  return 0;
}