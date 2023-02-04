#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 a, b;
  char c;
  cin >> a;
  cin >> c;
  cin >> b;

  if (c == '*') {
    cout << a * b << endl;
  } else {
    cout << a + b << endl; // tle, i did in python
  }

  return 0;
}