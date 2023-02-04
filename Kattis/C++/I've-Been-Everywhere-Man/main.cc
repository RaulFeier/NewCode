#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    set<string> v;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
      string ans;
      cin >> ans;
      v.insert(ans);
    }

    cout << v.size() << endl;
  }
}