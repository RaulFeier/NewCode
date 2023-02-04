#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  vector<i64> v;
  for (i64 i = 0; i < 10; i += 2) {
    v.push_back(i);
  }

  vector<i64> cv;
  cv = v;

  for (auto &i : cv) {
    cout << i << " ";
  }
}