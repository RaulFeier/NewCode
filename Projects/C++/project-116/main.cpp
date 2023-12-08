#include <bits/stdc++.h>

using namespace std;

class eep {
public:
  int a, b;
};

bool comp(eep a, eep b) {
  if (a.a > b.a) {
    return false;
  }

  return true;
}

int main() {
  vector<eep> v(4);
  v[0] = {5, 2};
  v[1] = {3, 3};
  v[2] = {8, 9};
  v[3] = {1, 4};

  sort(v.begin(), v.end(), comp);

  for (auto &x : v) {
    cout << x.a << " " << x.b << endl;
  }

  return 0;
}