#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long i64;
typedef int i32;
typedef short i16;
typedef vector<i64> vi64;
typedef vector<vi64> vv;
typedef string str;
typedef pair<i64, i64> p64;

i64 ver(str &s1, str &s2) {
  i64 crt = 0;

  for (i64 i = 0; i < s1.size(); i++) {
    for (i64 j = 0; j < s2.size(); j++) {
      if (s1[i] == s2[j]) {
        crt++;
      }
    }
  }

  return crt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  i64 n, res = 1e9;
  cin >> n;

  vi64 v(n);
  vector<str> s(n);
  for (i64 i = 0; i < n; i++) {
    cin >> s[i];
    v[i] = i;
  }

  map<pair<i64, i64>, i64> m;

  do {
    i64 crt = 0;
    for (i64 i = 0; i < n - 1; i++) {
      pair<i64, i64> p = {v[i], v[i + 1]};

      if (!m.count(p)) {
        m[p] = ver(s[v[i]], s[v[i + 1]]);
      }

      crt += m[p];
    }

    res = min(res, crt);

    if (res == 0) {
      break;
    }
  } while (next_permutation(v.begin(), v.end()));

  cout << res << endl;

  return 0;
}