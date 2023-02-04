#include <bits/stdc++.h>

using namespace std;

int main() {
  int b, k;
  int g;
  cin >> b >> k >> g;

  int t = k / g;

  cout << ceil(double(b - 1) / t) << endl;
}
