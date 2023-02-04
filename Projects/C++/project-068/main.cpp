#include <bits/stdc++.h>

using namespace std;

void f(int &a) {
  a++;
  if (a < 6) {
    f(a);
  }
}

int main() {
  int a = 0;

  f(a);

  cout << a << endl;
}