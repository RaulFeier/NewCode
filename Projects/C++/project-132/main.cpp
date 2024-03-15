#include <bits/stdc++.h>

using namespace std;

int main() {
  unordered_map<int, int> m;

  m[3] = 1;
  m[2] = 3;

  int a = m.count(3);
  int b = m.count(5);

  cout << a << endl;
  cout << b << endl;

  return 0;
}
