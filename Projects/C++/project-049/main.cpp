#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int t = __gcd(a, b);

  if ((a / t) * b <= c) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}