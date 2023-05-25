#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 tc;
  cin >> tc;

  while (tc--) {
    i64 n;
    cin >> n;

    string ans;
    cin >> ans;

    map<string, i64> m;
    for (i64 i = 0; i < ans.size() - 1; i++) {
      string a = "";
      a += ans[i];
      a += ans[i + 1];
      m[a]++;
    }

    cout << m.size() << endl;
  }

  return 0;
}

/*
ba
ab
bd
dd
*/