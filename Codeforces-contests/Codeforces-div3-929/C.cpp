#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tc;
  cin >> tc;

  while (tc--) {
    int a, b, l;
    cin >> a >> b >> l;

    set<int> s;
    while (true) {
      int x = l;
      while (true) {
        s.insert(x);
        if (x % b != 0) {
          break;
        }
        x /= b;
      }
      if (l % a != 0) {
        break;
      }
      l /= a;
    }

    cout << s.size() << endl;
  }

  return 0;
}