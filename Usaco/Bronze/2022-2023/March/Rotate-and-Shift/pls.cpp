#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k, t;
  cin >> n >> k >> t;

  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }

  int pos = 0;
  for (int i = 0; i < k; i++) {
    pos += a[i] + 1;
    pos %= n;
  }

  int rem = t % k;
  vector<int> order(n);
  for (int i = 0; i < n; i++) {
    order[(pos + i) % n] = i;
  }
  for (int i = 0; i < k; i++) {
    vector<int> new_order(n);
    for (int j = 0; j < n; j++) {
      new_order[(j + 1) % n] = order[j];
    }
    order = new_order;
    if (i == rem - 1) {
      for (int j = 0; j < n - 1; j++) {
        cout << order[j] << " ";
      }
      cout << order[n - 1];
    }
  }
  cout << endl;

  return 0;
}
