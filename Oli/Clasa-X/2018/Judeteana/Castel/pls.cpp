#include <bits/stdc++.h>

using namespace std;

int main() {
  for (int i = 0; i < 16; i++) {
    bitset<4> b(i);
    cout << i << ": ";
    cout << b << endl;
  }

  return 0;
}