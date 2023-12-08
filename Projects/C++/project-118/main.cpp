#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int t1, d1, t2, d2 = 0;
  int res = 0;
  for (int i = 0; i < n; i++) {
    cin >> t1 >> d1;

    if ((d1 - d2) / (t1 - t2) > res) {
      res = (d1 - d2) / (t1 - t2);
    }

    t2 = t1;
    d2 = d1;
  }

  cout << res << endl;

  return 0;
}