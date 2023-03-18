#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }

  return gcd(b, a % b);
}

int comb(int n, int k) {
  if (k > n) {
    return 0;
  }
}

int main() {

  int a, b;
  cin >> a >> b;

  return 0;
}