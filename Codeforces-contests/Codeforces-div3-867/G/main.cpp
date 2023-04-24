#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 2e5 + 5;
int a[MAXN];
map<ll, int> cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    cnt.clear();
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        ll ratio = (1ll * a[j]) / a[i];
        if (a[j] % a[i] != 0 || ratio > 1e6)
          continue; // ignore invalid ratios
        ans += cnt[ratio];
      }
      for (int j = 1; j < i; j++) {
        ll ratio = (1ll * a[i]) / a[j];
        if (a[i] % a[j] != 0 || ratio > 1e6)
          continue; // ignore invalid ratios
        cnt[ratio]++;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
