#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 l, c;
    cin >> l >> c;

    vector<vector<char>> v(l, vector<char>(c));
    for (i64 i = 0; i < l; i++) {
      for (i64 j = 0; j < c; j++) {
        cin >> v[i][j];
      }
    }

    set<pair<i64, char>> s;
    vector<bool> vb(c, false);
    vector<bool> vbb(4, false);
    for (i64 i = 0; i < c; i++) {
      for (i64 j = 0; j < l; j++) {
        char cc = v[j][i];
        if (cc == 'v' or cc == 'i' or cc == 'k' or cc == 'a') {
          if (!vb[i]) {
            if (cc == 'v' and !vbb[0]) {
              vb[i] = true;
              vbb[0] = true;
              s.insert({i, cc});
            } else if (cc == 'i' and vbb[0] == true and !vbb[1]) {
              vb[i] = true;
              s.insert({i, cc});
              vbb[1] = true;
            } else if (cc == 'k' and vbb[1] == true and !vbb[2]) {
              vb[i] = true;
              s.insert({i, cc});
              vbb[2] = true;
            } else if (cc == 'a' and vbb[2] == true and !vbb[3]) {
              vb[i] = true;
              s.insert({i, cc});
              vbb[3] = true;
            }
          }
        }
      }
    }

    str ss;
    for (auto &x : s) {
      ss.push_back(x.second);
    }

    if (ss == "vika") {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}