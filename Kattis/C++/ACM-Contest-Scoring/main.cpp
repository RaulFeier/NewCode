#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef long double d64;
typedef vector<i64> v;
typedef vector<vector<i64>> vv;

int main() {

  i64 n, crtt = 0, crtp = 0, pen = 0;
  vector<char> pg;
  vector<char> pw;
  char p, b;
  string ans;

  while (cin >> n) {
    if (n == -1) {
      break;
    }
    cin >> p >> ans;
    if (ans == "right") {
      crtp++;
      crtt += n;
      pg.push_back(p);
    } else if (ans == "wrong") {
      pw.push_back(p);
    }
  }

  sort(pg.begin(), pg.end());
  sort(pw.begin(), pw.end());

  if (pg.size() > pw.size()) {
    for (i64 i = 0; i < pg.size(); i++) {
      for (i64 j = 0; j < pw.size(); j++) {
        if (pg[i] == pw[j]) {
          pen++;
        }
      }
    }
  } else {
    for (i64 i = 0; i < pw.size(); i++) {
      for (i64 j = 0; j < pg.size(); j++) {
        if (pw[i] == pg[j]) {
          pen++;
        }
      }
    }
  }

  crtt += pen * 20;
  cout << crtp << " " << crtt;
  return 0;
}