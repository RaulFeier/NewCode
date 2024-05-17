#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int add(int a, int b) { return a + b; }

int main() {
  i64 n;
  cin >> n;

  vector<i64> v;
  for (i64 i = 0; i < n; i++) {
    i64 x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  cout << add(2, 3) << endl;

  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < 2; j++) {
      if (j == 1) {
        break;
      }
    }
    cout << v[i] << " ";
  }
}
