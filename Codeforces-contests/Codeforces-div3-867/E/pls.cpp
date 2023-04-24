#include <cstring>
#include <iostream>
#define endl '\n'

using namespace std;

int t, n;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n / 2; i++) {
      int j = n - i - 1;
      if (s[i] == s[j]) {
        cnt++;
      }
    }
    if (cnt == n / 2) {
      cout << "-1\n";
      continue;
    }
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
      int j = n - i - 1;
      if (s[i] != s[j]) {
        bool found = false;
        for (int k = j - 1; k >= i + 1; k--) {
          if (s[k] == s[i]) {
            ans += j - k;
            swap(s[j], s[k]);
            found = true;
            break;
          }
        }
        if (!found) {
          for (int k = i + 1; k <= j - 1; k++) {
            if (s[k] == s[j]) {
              ans += k - i;
              swap(s[i], s[k]);
              break;
            }
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
