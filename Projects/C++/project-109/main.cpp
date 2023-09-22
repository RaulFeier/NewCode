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
  str s;
  cin >> t;
  cin.ignore();

  for (i64 i = 0; i < t; i++) {
    getline(cin, s);

    if (s.size() < 10) {
      cout << endl;
      continue;
    }

    str ss = s.substr(0, 10);
    if (ss == "simon says" and s.size() > 10) {
      cout << s.substr(11, s.size()) << endl;
    } else {
      cout << endl;
    }
  }

  return 0;
}