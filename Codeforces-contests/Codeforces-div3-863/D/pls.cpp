#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> fib;
  fib.push_back(1);
  fib.push_back(1);

  while (fib.back() < x) {
    int next = fib[fib.size() - 1] + fib[fib.size() - 2];
    fib.push_back(next);
  }

  if (fib.back() != x) {
    cout << "NO" << endl;
    return 0;
  }

  if (fib.size() < n) {
    cout << "NO" << endl;
    return 0;
  }

  int count = 0;
  for (int i = fib.size() - 1; i >= 0 && count < n; i--) {
    if (x >= fib[i]) {
      x -= fib[i];
      count++;
    }
  }

  if (count == n) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
