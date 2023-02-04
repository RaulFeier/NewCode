#include <bits/stdc++.h>

using namespace std;

int max(int a, int b, vector<int> &v) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int a = 60;
  int b = 28;

  vector<int> v;
  gcd(a, b);
  max(a, b, v);
}