#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;
typedef vector<p64> vp64;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n;
  cin >> n;
  cin.ignore();

  while (n--) {
    str s;
    getline(cin, s);

    list<char> d;
    bool pushb = true;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '<' and !d.empty()) {
        d.pop_back();
      } else if (s[i] == ']') {
        pushb = true;
      } else if (s[i] == '[') {
        pushb = false;
      } else {
        if (pushb) {
          d.push_back(s[i]);
        } else {
          list<char> ss;
          for (; i < s.size(); i++) {
            if (s[i] == '<' and !ss.empty()) {
              ss.pop_back();
            } else if (s[i] == ']' or s[i] == '[') {
              pushb = (s[i] == ']') ? true : false;
              break;
            } else {
              ss.push_back(s[i]);
            }
          }

          d.splice(d.begin(), ss);
        }
      }
    }

    for (auto &x : d) {
      cout << x;
    }
    cout << endl;
  }

  return 0;
}

/*
[Riana e smechera
Riana[ e[][s]
*/
