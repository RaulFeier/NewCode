#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    int64_t lhs = 0;
    if (i > 0 && s[i - 1] != s[i]) {
      lhs++;
      for (int k = i - 2; k >= 0 && s[k] == s[i - 1]; k--)
        lhs++;
    }
    int64_t rhs = 0;
    if (i + 1 < n && s[i + 1] != s[i]) {
      rhs++;
      for (int k = i + 2; k < n && s[k] == s[i + 1]; k++)
        rhs++;
    }
    ans += lhs * rhs + max(lhs - 1, (int64_t)0) + max(rhs - 1, (int64_t)0);
  }
  cout << ans << "\n";
}