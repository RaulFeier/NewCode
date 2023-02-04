#include <bits/stdc++.h>

using namespace std;
typedef long long i64;

int main() {
  vector<string> v;
  string c;
  bool k = true;
  i64 a, b, d = 0;
  while (getline(cin, c)) {
    if (k) {
      a = c.size() - 1;
      b = c.size();
      k = false;
    }
    if (c == "") {
      for (i64 i = 0; i < v.size(); i++) {
        for (i64 j = 0; j < v[i].size() - d; j++) {
          if (v[i][j] == '*') {
            d++;
            swap(v[i][j], v[i][a]);
            a--;
          }
        }
      }
      for (i64 i = 0; i < v.size(); i++) {
        for (i64 j = 0; j < v[i].size(); j++) {
          cout << v[i][j];
        }
        cout << endl;
      }
      v.clear();
      k = true;
      d = 0;
    } else {
      v.push_back(c);
    }
  }
}