#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 n;
  cin >> n;

  vector<i64> v;
  while (n--) {
    i64 temp;
    cin >> temp;
    v.push_back(temp);
  }

  reverse(v.begin(), v.end());

  vector<i64> cv;
  i64 t = 0;
  while (true) {
    for (i64 i = v.size() - 1; i >= 0; i--) {
      if ((v[i] + v[i - 1]) % 2 == 0 && i != 0) {
        i--;
      } else {
        cv.push_back(v[i]);
      }
    }
    if (t == cv.size()) {
      break;
    }
    t = cv.size();
    v = cv;
    reverse(v.begin(), v.end());
    cv.clear();
  }

  cout << t << endl;

  return 0;
}