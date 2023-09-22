#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    long long maxProduct = a[0];
    int l = 1, r = 1;
    long long maxEndingHere = a[0];
    long long minEndingHere = a[0];

    for (int i = 1; i < n; i++) {
      if (a[i] < 0) {
        swap(maxEndingHere, minEndingHere);
      }

      maxEndingHere = max(1LL * a[i], 1LL * maxEndingHere * a[i]);
      minEndingHere = min(1LL * a[i], 1LL * minEndingHere * a[i]);

      if (maxEndingHere > maxProduct) {
        maxProduct = maxEndingHere;
        r = i + 1;
        l = (minEndingHere == 0) ? (i + 1) : l;
      }
    }

    cout << l << " " << r << endl;
  }

  return 0;
}
