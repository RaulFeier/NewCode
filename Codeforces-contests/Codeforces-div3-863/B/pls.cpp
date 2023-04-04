#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    int xc = (n + 1) / 2, yc = (n + 1) / 2;
    int dx = abs(x2 - x1), dy = abs(y2 - y1);
    int ans = dx + dy;
    if (x1 == x2 && x1 == xc) {
      int d = abs(y2 - y1);
      ans += (d % 2 == 0 ? 0 : 2);
    } else if (y1 == y2 && y1 == yc) {
      int d = abs(x2 - x1);
      ans += (d % 2 == 0 ? 0 : 2);
    } else {
      ans += 2;
    }
    cout << ans << endl;
  }
  return 0;
}
