#include <bits/stdc++.h>

using namespace std;

int main() {
  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;

    deque<int> v;

    for (int i = 0; i < n * 3; i++) {
      int a;
      cin >> a;
      v.push_back(a);
    }

    sort(v.begin(), v.end());

    int total = 0;
    while (!v.empty()) {
      v.pop_back();
      total += v.back();
      v.pop_back();
      v.pop_front();
    }

    cout << total << endl;
  }

  return 0;
}
