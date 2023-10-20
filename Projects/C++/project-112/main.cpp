#include <bits/stdc++.h>

using namespace std;

int main() {
  string ans;
  cin >> ans;

  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
