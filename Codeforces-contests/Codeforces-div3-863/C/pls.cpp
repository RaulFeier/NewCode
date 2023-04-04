#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    vector<int> b(n - 1);
    for (int j = 0; j < n - 1; j++) {
      cin >> b[j];
    }

    vector<int> a(n);
    a[0] = b[0];
    a[1] = max(b[0], b[1]);
    for (int j = 2; j < n; j++) {
      a[j] = max(a[j - 1], a[j - 2] + b[j - 1]);
    }

    for (int j = 0; j < n - 2; j++) {
      cout << max(b[j], b[j + 1]) << " ";
    }
    cout << a[n - 2] << endl;
  }

  return 0;
}
