#include <bits/stdc++.h>

using namespace std;

short to_binary(short n) {
  if (n == 0) {
    return 0;
  } else {
    return (n % 2 + 10 * to_binary(n / 2));
  }
}

int main() { cout << to_binary(9) << endl; }