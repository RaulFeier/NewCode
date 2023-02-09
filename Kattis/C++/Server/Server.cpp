#include <cmath>
#include <iostream>

using namespace std;
typedef int64_t i64;

int main() {
  i64 n, t, s = 0, b = -1, a;
  cin >> n >> t;
  i64 i = 0;

  for (i = 0; i < n; i++) {
    cin >> a;
    s += a;

    if (s > t) {
      break;
    }
  }
  cout << i << "\n";
}