#include <bits/stdc++.h>

using namespace std;

int main() {
  string ans, p;
  cin >> ans >> p;
  if (ans[ans.size() - 1] == 'e') {
    cout << ans << "x" << p << endl;
  } else if (ans[ans.size() - 1] == 'a' || ans[ans.size() - 1] == 'a' ||
             ans[ans.size() - 1] == 'i' || ans[ans.size() - 1] == 'o' ||
             ans[ans.size() - 1] == 'u') {
    for (int i = 0; i < ans.size() - 1; i++) {
      cout << ans[i];
    }
    cout << "ex" << p << endl;
  } else if (ans[ans.size() - 1] == 'x' && ans[ans.size() - 2] == 'e') {
    cout << ans << p << endl;
  } else {
    cout << ans << "ex" << p << endl;
  }
}