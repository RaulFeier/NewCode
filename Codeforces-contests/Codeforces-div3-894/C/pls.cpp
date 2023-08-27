#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
      cin >> heights[i];
    }

    bool symmetrical = true;
    int left = 0, right = n - 1;

    while (left <= right) {
      if (heights[left] != heights[right]) {
        symmetrical = false;
        break;
      }
      left++;
      right--;
    }

    if (symmetrical) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
