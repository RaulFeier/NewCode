#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  string ans;
  cin >> ans;

  vector<char> v;

  for (i64 i = 0; i < ans.size(); i++) {
    if (i == 0) {
      v.push_back(ans[i]);
    }
    if (ans[i] == '-') {
      v.push_back(ans[i + 1]);
      i++;
    }
  }

  for (i64 i = 0; i < v.size(); i++) {
    cout << v[i];
  }
  cout << endl;
}