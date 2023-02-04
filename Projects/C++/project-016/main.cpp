#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> p(N + 1), t(N + 1), d(N + 2);
  for (int i = 1; i <= N; ++i)
    cin >> p[i];
  for (int i = 1; i <= N; ++i)
    cin >> t[i];
  for (int i = 1; i <= N; ++i)
    d[i] = p[i] - t[i];
  int ans = 0;
  for (int i = 0; i <= N; ++i)
    ans += abs(d[i] - d[i + 1]);
  cout << ans / 2;
}
