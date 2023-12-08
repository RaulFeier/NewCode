#include <bits/stdc++.h>

using namespace std;

struct eep {
  int a, b;
};

int main() {
  vector<eep> v(4);
  v[0] = {5, 2};
  v[1] = {3, 3};
  v[2] = {8, 9};
  v[3] = {1, 4};

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++) {
    cout << v[i].a << endl;
  }

  return 0;
}