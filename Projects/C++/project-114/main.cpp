#include <bits/stdc++.h>

using namespace std;

int main() {
  string ans;
  cin >> ans;

  unordered_set<char> p;

  while (ans.size() != 0) {
    p.insert(ans.back());
    ans.pop_back();
  }

  for (auto &c : p) {
    cout << c;
  }

  cout << endl;

  return 0;
}
