#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
typedef int i32;
typedef short i16;
typedef int8_t i8;
typedef vector<i64> vi64;
typedef vector<vi64> vv;

void solve1(i32 &n) {
  ifstream cin{"cufar.in"};
  ofstream cout{"cufar.out"};

  i32 l, m;
  cin >> l >> m;

  while (n--) {
    i32 a, k, crt = 0;
    cin >> a >> k;
    i32 x = a;

    if (a % 2 == 0) {
      crt++;
      if (crt == k) {
        cout << 2 << endl;
        continue;
      }

      while (a % 2 == 0) {
        a /= 2;
      }
    }

    for (i32 i = 3; i <= x; i += 2) {
      if (a % i == 0) {
        crt++;
        if (crt == k) {
          cout << i << endl;
          break;
        }

        while (a % i == 0) {
          a /= i;
        }
      }
    }
  }
}

void solve2(i32 &n) {
  ifstream cin{"cufar.in"};
  ofstream cout{"cufar.out"};

  map<pair<i32, i32>, i32> p;
  map<pair<i32, i32>, i32> o;
  i32 l, m, sum = 0, a, k;
  cin >> l >> m >> a >> k;

  while (n--) {
    i32 x = a, crt = 0;

    if (p[{a, k}] < 1) {
      p[{a, k}]++;

      if (a % 2 == 0) {
        crt++;
        if (crt == k) {
          sum += 2;
          o[{a, k}] = 2;
          cin >> a >> k;
          continue;
        }

        while (a % 2 == 0) {
          a /= 2;
        }
      }

      for (i32 i = 3; i <= x; i += 2) {
        if (a % i == 0) {
          crt++;
          if (crt == k) {
            o[{a, k}] = i;
            sum += i;
            break;
          }

          while (a % i == 0) {
            a /= i;
          }
        }
      }
    } else {
      sum += o[{a, k}];
    }

    cin >> a >> k;
  }

  cout << sum << endl;
}

int main() {
  ifstream cin{"cufar.in"};

  i8 p;
  i32 n;
  cin >> p >> n;

  if (p == '1') {
    solve1(n);
  } else {
    solve2(n);
  }

  return 0;
}