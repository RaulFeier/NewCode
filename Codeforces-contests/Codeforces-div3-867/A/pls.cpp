#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main() {
  int q;
  cin >> q;

  while (q--) {
    int n, t;
    cin >> n >> t;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    int max_entertainment = -1, max_entertainment_index = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] <= t) {
        if (b[i] > max_entertainment) {
          max_entertainment = b[i];
          max_entertainment_index = i + 1;
        }
      }
    }

    cout << max_entertainment_index << endl;
  }

  return 0;
}
