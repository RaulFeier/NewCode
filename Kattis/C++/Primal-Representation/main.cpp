#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll n;

  while (cin >> n) {
    if (n < 0) {
      cout << "-1 ";
      n = abs(n);
    }

    ll k = 0;

    for (ll i = 2; i <= sqrt(n); i++) {
      while (n % i == 0) {
        n /= i;
        k++;
      }
      if (k > 0) {
        cout << i;
        if (k > 1) {
          cout << "^" << k;
        }
        cout << " ";
        k = 0;
      }
    }

    if (n > 1) {
      cout << n;
    }
    cout << endl;
  }

  return 0;
}
