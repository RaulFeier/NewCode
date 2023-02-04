#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> a = {1, 6, 4, 6};

  double b = 0;

  for (auto &x : a) {
    b += (1.0 / x);
  }

  cout << 4 / b << endl;
}