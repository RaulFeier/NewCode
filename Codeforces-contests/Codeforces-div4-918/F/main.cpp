#include <bits/stdc++.h>

using namespace std;
using i32 = int;

int main() {
#ifdef LOCAL
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  i32 tc;
  scanf("%d", &tc);

  while (tc--) {
    i32 n;
    scanf("%d", &n);

    map<i32, i32> m;

    for (i32 i = 0; i < n; i++) {
      i32 a, b;
      scanf("%d %d", &a, &b);
      m[a] = b;
    }

    i32 total = 0;

    for (auto i = m.begin(); i != m.end(); i++) {
      for (auto j = i; j != m.end(); j++) {
        if (i->second > j->second and i->first != j->first) {
          total++;
        }
      }
    }

    printf("%d\n", total);
  }

  return 0;
}

/*

*/