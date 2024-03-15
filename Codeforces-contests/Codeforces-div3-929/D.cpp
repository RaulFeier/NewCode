#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    vector<int> v(n);
    int mn = 1e9;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      mn = min(mn, v[i]);
    }

    bool found = false;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] % mn != 0) {
        found = true;
        break;
      }
      if (v[i] == mn) {
        cnt++;
      }
    }

    if (found or cnt == 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}