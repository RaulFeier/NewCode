#include <cmath>
#include <iostream>
using namespace std;

long long getLiveSequenceNumber(long long k) {
  long long lo = 1, hi = 1e18, mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    long long cnt = mid - (mid / 10) - ((mid / 100) * 9) -
                    ((mid / 1000) * 9 * 9) - ((mid / 10000) * 9 * 9 * 9);
    if (cnt >= k) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    cout << getLiveSequenceNumber(k) << endl;
  }
  return 0;
}
