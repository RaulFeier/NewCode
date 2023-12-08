#include <bits/stdc++.h>

using namespace std;

int solve(int a, int steps) {
  if (a == 1) {
    return steps;
  }

  if (a % 2 == 0) {
    return solve(a / 2, ++steps);
  }

  return solve(a * 3 + 1, ++steps);
}

int main() {
  int a;
  cin >> a;

  cout << solve(a, 0) << endl;
}