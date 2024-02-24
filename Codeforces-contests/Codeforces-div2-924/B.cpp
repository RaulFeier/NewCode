#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    vector<i64> a(n);

    for (auto &c : a) {
      cin >> c;
    }

    sort(a.begin(), a.end());

    map<i64, i64> m;

    i64 p = n;
    for (auto &c : a) {
      c += p;
      m[c]++;
      p--;
    }

    cout << m.begin()->second << endl;
  }

  return 0;
}

/*
1 1 4 7
3 4 1 2
 */