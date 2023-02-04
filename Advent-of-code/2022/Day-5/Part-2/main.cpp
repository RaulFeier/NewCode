#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef vector<i64> v64;

int main() {
  vector<char> v1 = {'Q', 'S', 'W', 'C', 'Z', 'V', 'F', 'T'};
  vector<char> v2 = {'Q', 'R', 'B'};
  vector<char> v3 = {'B', 'Z', 'T', 'Q', 'P', 'M', 'S'};
  vector<char> v4 = {'D', 'V', 'F', 'R', 'Q', 'H'};
  vector<char> v5 = {'J', 'G', 'L', 'D', 'B', 'S', 'T', 'P'};
  vector<char> v6 = {'W', 'R', 'T', 'Z'};
  vector<char> v7 = {'H', 'Q', 'M', 'N', 'S', 'F', 'R', 'J'};
  vector<char> v8 = {'R', 'N', 'F', 'H', 'W'};
  vector<char> v9 = {'J', 'Z', 'T', 'Q', 'P', 'R', 'B'};

  i64 x, y, n;
  string a, b, c;

  vector<vector<char>> s = {v1, v2, v3, v4, v5, v6, v7, v8, v9};

  ifstream cin("input.txt");
  ofstream cout("output.txt");

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

  for (i64 i = 0; i < 9; i++) {
    cout << s[i].back();
  }
  cout << endl;
  return 0;
}