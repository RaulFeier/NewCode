#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  int left = 0, right = 0;
  int maxLen = 0, bestLeft = 0, zeroCount = 0;

  while (right < n) {
    if (s[right] == '0') {
      zeroCount++;
    }

    while (zeroCount > k) {
      if (s[left] == '0') {
        zeroCount--;
      }
      left++;
    }

    if (right - left + 1 > maxLen) {
      maxLen = right - left + 1;
      bestLeft = left;
    }

    right++;
  }

  cout << maxLen << endl;
  for (int i = 0; i < n; i++) {
    if (i >= bestLeft && i < bestLeft + maxLen) {
      cout << '1';
    } else {
      cout << s[i];
    }
  }

  return 0;
}
