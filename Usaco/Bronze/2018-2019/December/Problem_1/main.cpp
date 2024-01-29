#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  ifstream cin{"mixmilk.in"};
  ofstream cout{"mixmilk.out"};

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  pair<i64, i64> p1, p2, p3;
  cin >> p1.first >> p1.second;
  cin >> p2.first >> p2.second;
  cin >> p3.first >> p3.second;

  for (i64 i = 0; i < 33; i++) {
    if (p1.second + p2.second <= p2.first) {
      p2.second += p1.second;
      p1.second = 0;
    } else {
      i64 crt = p2.first - p2.second;
      p1.second -= crt;
      p2.second += crt;
    }

    if (p2.second + p3.second <= p3.first) {
      p3.second += p2.second;
      p2.second = 0;
    } else {
      i64 crt = p3.first - p3.second;
      p2.second -= crt;
      p3.second += crt;
    }

    if (p3.second + p1.second <= p1.first) {
      p1.second += p3.second;
      p3.second = 0;
    } else {
      i64 crt = p1.first - p1.second;
      p3.second -= crt;
      p1.second += crt;
    }
  }

  if (p1.second + p2.second <= p2.first) {
    p2.second += p1.second;
    p1.second = 0;
  } else {
    i64 crt = p2.first - p2.second;
    p1.second -= crt;
    p2.second += crt;
  }

  cout << p1.second << endl;
  cout << p2.second << endl;
  cout << p3.second << endl;

  return 0;
}