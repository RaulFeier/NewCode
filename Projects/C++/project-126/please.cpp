#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  // ifstream cin{"input.txt"};
  // ofstream cout{"output.txt"};

  i64 tc;
  cin >> tc;

  bool masa = false;
  while (tc--) {
    string ans;
    if (!masa) {
      getline(cin, ans);
      masa = true;
    }
    getline(cin, ans);

    list<char> end;
    list<char> home;
    bool eep = false;

    for (auto &x : ans) {
      if (x == '[') {
        eep = true;
        if (!home.empty()) {
          end.splice(end.begin(), home);
          home.clear();
        }
        continue;
      }
      if (x == ']') {
        eep = false;
        continue;
      }

      if (eep) {
        if (x == '<') {
          if (!home.empty()) {
            home.pop_back();
          }
        } else {
          home.push_back(x);
        }
      } else {
        if (x == '<') {
          if (!end.empty()) {
            end.pop_back();
          }
        } else {
          end.push_back(x);
        }
      }
    }

    if (!home.empty()) {
      end.splice(end.begin(), home);
      home.clear();
    }

    for (auto &x : end) {
      cout << x;
    }

    cout << endl;
  }

  return 0;
}