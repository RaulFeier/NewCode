#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int max_catch_frogs(const vector<int> &hops) {
  int n = hops.size();
  vector<int> positions(n);

  for (int i = 0; i < n; ++i) {
    positions[i] = i + hops[i];
  }

  sort(positions.begin(), positions.end());

  int max_frogs = 0;
  int current_frogs = 1;
  for (int i = 1; i < n; ++i) {
    if (positions[i] == positions[i - 1]) {
      current_frogs++;
    } else {
      max_frogs = max(max_frogs, current_frogs);
      current_frogs = 1;
    }
  }
  max_frogs = max(max_frogs, current_frogs);

  return max_frogs;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> hops(n);
    for (int i = 0; i < n; ++i) {
      cin >> hops[i];
    }
    cout << max_catch_frogs(hops) << endl;
  }
  return 0;
}
