#include <bits/stdc++.h>

using namespace std;

int main() {
  string ans = "Ham";

  string cp = "";
  for (int i = 0; i < 3; i++) {
    if (ans[i] >= 65 and ans[i] <= 90) {
      cp += ans[i] + 32;
    } else {
      cp += ans[i] - 32;
    }
  }

  ans = ans + cp + cp + ans;

  cout << ans << endl;
}