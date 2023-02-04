#include <iostream>
using namespace ::std;

int checker(int n) {
  int s = 0;
  while (n > 0) {
    s += n % 10;
    n /= 10;
  }
  return s;
}

int main() {
  int n, a;
  cin >> n;
  while (n > 0) {
    a = 11;
    while (checker(n) != checker(n * a)) {
      a++;
    }
    cout << a << endl;
    cin >> n;
  }
  return 0;
}