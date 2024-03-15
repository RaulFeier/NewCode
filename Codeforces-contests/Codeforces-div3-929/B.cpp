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

    int sum = 0;
    set<int> s;

    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      s.insert(c % 3);
      sum += c;
    }

    if (sum % 3 == 0) {
      cout << 0 << endl;
      continue;
    } else if (sum % 3 == 2) {
      cout << 1 << endl;
      continue;
    } else {
      if (s.count(1)) {
        cout << 1 << endl;
      } else {
        cout << 2 << endl;
      }
    }
  }

  return 0;
}