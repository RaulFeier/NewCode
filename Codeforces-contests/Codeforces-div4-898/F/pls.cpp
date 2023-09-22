#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> h(n);
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<int> dp(n, 1);

    int maxLength = 1;

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (h[i] % h[j] == 0 && a[i] + a[j] <= x) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      maxLength = max(maxLength, dp[i]);
    }

    cout << maxLength << endl;
  }
}