#include <bits/stdc++.h>

using namespace std;

int solve1(int n, vector<int> &v) {
  int max = 0, crt = 0;

  if (v[n - 1] <= v[0]) {
    crt++;
    int x;

    for (int i = 1; i < n; i++) {
      if (v[i] >= v[i - 1]) {
        crt++;
      } else {
        x = i;
        break;
      }
    }

    for (int i = n - 1; i > x; i--) {
      if (v[i] >= v[i - 1]) {
        crt++;
      } else {
        break;
      }
    }

    if (crt > max) {
      max = crt;
    }

    crt = 0;

    for (int i = 1; i < n; i++) {
      if (v[i] >= v[i - 1]) {
        crt++;
        if (crt > max) {
          max = crt;
        }
      } else {
        crt = 0;
      }
    }
  } else {
    crt = 0;

    for (int i = 1; i < n; i++) {
      if (v[i] >= v[i - 1]) {
        crt++;
        if (crt > max) {
          max = crt;
        }
      } else {
        crt = 0;
      }
    }
  }

  return max + 1;
}

void solve2(int n, vector<int> &v) {}

int main() {
  ifstream cin{"roboti3.in"};
  ofstream cout{"roboti3.out"};

  char p;
  cin >> p;
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  if (p == '1') {
    cout << solve1(n, v) << endl;
  } else {
    solve2(n, v);
  }
  return 0;
}