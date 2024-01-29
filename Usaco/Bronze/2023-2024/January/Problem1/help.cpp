#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;

    vector<int> h(N);
    for (int i = 0; i < N; ++i) {
      cin >> h[i];
    }

    int majority = (N + 1) / 2;
    bool possible = false;

    for (int i = 0; i < N; ++i) {
      unordered_map<int, int> count;
      for (int j = i; j < N; ++j) {
        count[h[j]]++;
        if (count[h[j]] >= majority) {
          possible = true;
          cout << h[j] << " ";
          break;
        }
      }
      if (possible)
        break;
    }

    if (!possible)
      cout << "-1";
    cout << '\n';
  }
  return 0;
}
