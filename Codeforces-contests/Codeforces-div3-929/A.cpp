#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
      int p;
      cin >> p;
      sum += abs(p);
    }

    cout << sum << "\n";
  }

  return 0;
}