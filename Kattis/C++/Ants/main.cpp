#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  cin >> tc;

  while (tc--) {
    int n, m;
    cin >> n >> m;

    vector<int> v(m);

    for (auto &x : v) {
      cin >> x;
    }

    int l = min(v[0], n - v[0]);
    int h = max(v[0], n - v[0]);

    for (auto x : v) {
      l = max(l, min(x, n - x));
      h = max(h, max(x, n - x));
    }

    cout << l << " " << h << endl;
  }
}
