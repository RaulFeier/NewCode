#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> v64;

int main() {

  vector<char> v1 = {'F', 'H', 'B', 'V', 'R', 'Q', 'D', 'P'};
  vector<char> v2 = {'L', 'D', 'Z', 'Q', 'W', 'V'};
  vector<char> v3 = {'H', 'L', 'Z', 'Q', 'G', 'R', 'P', 'C'};
  vector<char> v4 = {'R', 'D', 'H', 'F', 'J', 'V', 'B'};
  vector<char> v5 = {'Z', 'W', 'L', 'C'};
  vector<char> v6 = {'J', 'R', 'P', 'N', 'T', 'G', 'V', 'M'};
  vector<char> v7 = {'J', 'R', 'L', 'V', 'M', 'B', 'S'};
  vector<char> v8 = {'D', 'P', 'J'};
  vector<char> v9 = {'D', 'C', 'N', 'W', 'V'};
  i64 x, y, n;
  string a, b, c;
  vector<vector<char>> s = {v1, v2, v3, v4, v5, v6, v7, v8, v9};

  while (cin >> a >> n >> b >> x >> c >> y) {
    x--;
    y--;
    vector<char> c;
    for (i64 i = 0; i < n; i++) {
      c.push_back(s[x].back());
      s[x].pop_back();
    }
    for (i64 i = 0; i < n; i++) {
      s[y].push_back(c.back());
      c.pop_back();
    }
  }

  for (i64 i = 0; i < s.size(); i++) {
    cout << s[i].back();
  }
  return 0;
}

/*cod scris de iubirea mea*/