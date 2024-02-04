#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 power_of_two(i64 k) {
  i64 n = 1;

  while (n < k) {
    n *= 2;
  }

  return n;
}

void breaks(i64 n, i64 k, i64 nr) {
  if (k == 0) {
    return;
  }

  breaks(n / 2, k - (n / 2), ++nr);
}

int main() {
  i64 k;

  int n;
  cin >> n;

  int bar = 1;

  int powerof2 = 0;
  while (bar < n) {
    bar *= 2;
    powerof2++;
  }

  int temp = bar - n;

  vector<int> bits;
  while (temp > 0) {
    if (temp % 2 == 0) {
      bits.push_back(0);
    }
    if (temp % 2 == 1) {
      bits.push_back(1);
    }
    temp >>= 1;
  }

  while (bits.size() < powerof2) {
    bits.push_back(0);
  }

  reverse(bits.begin(), bits.end());

  int breaks = 0;
  for (int i = 0; i < bits.size(); i++) {
    if (bits[i] == 1) {
      breaks = i + 1;
    }
  }

  cout << bar << " " << breaks << endl;

  return 0;
}