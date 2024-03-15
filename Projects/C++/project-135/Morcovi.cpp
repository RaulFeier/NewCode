#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
  int tc;
  cin >> tc;

  while (tc--) {
    int n, k;
    cin >> n >> k;

    cout << lcm(n, k) << endl;
  }

  return 0;
}