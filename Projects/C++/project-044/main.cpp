#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {

  i64 r, n;
  cin >> r >> n;

  vector<bool> v;
  v.resize(r, false);

  for (i64 i = 0; i < n; i++) {
    i64 a;
    cin >> a;
    v[a] = true;
  }

  if (n == r) {
    cout << "too late" << endl;
  }

  for (i64 i = 1; i <= v.size(); i++) {
    if (!v[i]) {
      cout << i << endl;
      return 0;
    }
  }
}