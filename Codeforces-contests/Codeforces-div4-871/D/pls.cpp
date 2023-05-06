#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 t;
  cin >> t;

  while (t--) {
    i64 n, m;
    cin >> n >> m;

    if (n > m && n % 3 == 0) {
      deque<i64> q;
      q.push_back(n / 3);
      q.push_back(n / 3 * 2);

      bool ok = true;
      while (!q.empty()) {
        i64 nn = q.front();
        if (nn == m) {
          cout << "YES" << endl;
          ok = false;
          break;
        }

        if (nn % 3 == 0) {
          i64 a = nn / 3, b = nn / 3 * 2;
          if (a == m || b == m) {
            cout << "YES" << endl;
            ok = false;
            break;
          }

          if (a % 3 == 0) {
            q.push_back(a);
          }
          if (b % 3 == 0) {
            q.push_back(b);
          }
        }

        q.pop_front();
      }

      if (ok) {
        cout << "NO" << endl;
      }
    } else if (n == m) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}