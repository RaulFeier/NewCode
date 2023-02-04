#include <bits/stdc++.h>

using namespace std;

void citire(vector<int> &v) {
  for (int i = 0; i < 4; i++) {
    cin >> v[i];
  }
}

int main() {
  vector<int> v(4);
  citire(v);

  for (auto &x : v) {
    cout << x << " ";
  }
}