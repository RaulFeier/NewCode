#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main() {
  i64 t;
  cin >> t;
  for (i64 i = 0; i < t; i++) {
    i64 n;
    cin >> n;
    vector<i64> v(n);
    for (i64 j = 0; j < n; j++) {
      cin >> v[j];
    }
    for (i64 j = 0; j < n - 1; j++) {
      if (v[j] != v[j + 1] - 1) {
        cout << j + 2 << endl;
        break;
      }
    }
  }
}

// cv?