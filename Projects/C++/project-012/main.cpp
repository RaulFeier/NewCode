#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  set<pair<i64, string>> v;

  v.insert({1, "haha"});

  v.insert({2, "gioni"});

  for (i64 i = 0; i < 3; i++) {
    for (i64 j = 0; j < 4; j++) {
      cout << i << endl;
    }
  }

  for (i64 i = 0; i < 5; i++) {
    cout << i << endl;
  }

  for (i64 j = 0; j < 7; j++) {
    cout << j << endl;
  }
}