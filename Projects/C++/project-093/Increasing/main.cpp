#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    sort(v.begin(), v.end());

    if (v.size() == 1) {
      cout << "YES" << endl;
      continue;
    }

    bool eep = false;
    for (int i = 1; i < n; i++) {
      if (v[i - 1] == v[i]) {
        eep = true;
        break;
      }
    }

    if (eep) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }

  return 0;
}