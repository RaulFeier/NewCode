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
    string ans;
    cin >> ans;

    string eep = "1234567890";
    i64 total = 0;
    i64 where = 0;
    for (i64 i = 0; i < 4; i++) {
      if (ans[i] != '0' and eep[where] == '0') {
        where--;
        total++;
      }

      if (ans[i] == '0') {
        for (i64 j = where; j < 10; j++) {
          if (eep[j] == ans[i]) {
            total++;
            where = j;
            break;
          } else {
            total++;
          }
        }
      } else if (ans[i] >= eep[where]) {
        for (i64 j = where; j < 10; j++) {
          if (eep[j] == ans[i]) {
            total++;
            where = j;
            break;
          } else {
            total++;
          }
        }
      } else {
        for (i64 j = where; j >= 0; j--) {
          if (eep[j] == ans[i]) {
            total++;
            where = j;
            break;
          } else {
            total++;
          }
        }
      }
    }

    cout << total << endl;
  }

  return 0;
}