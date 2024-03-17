#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  // ifstream cin{"concurs.in"};
  // ofstream cout{"concurs.out"};

  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tc;
  cin >> tc;

  while (tc--) {
    int64_t a, b, c, d;
    cin >> a >> b >> c >> d;

    unordered_set<i64> s;
    for (i64 i = a; i <= b; i++) {
      s.insert(i);
    }

    i64 ans = 1;
    for (i64 i = c; i <= d; i++) {
      vector<i64> deletes;
      ans *= i;
      for (auto &cc : s) {
        if (ans % cc == 0) {
          ans /= cc;
          deletes.push_back(cc);
        }
      }

      if (deletes.size() > 0) {
        while (deletes.size() > 0) {
          s.erase(deletes.back());
          deletes.pop_back();
        }
      }
    }

    if (s.size() == 0) {
      cout << "DA" << '\n';
    } else {
      cout << "NU" << '\n';
    }
  }

  return 0;
}