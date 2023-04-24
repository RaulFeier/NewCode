#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream cin("input.txt");
  ofstream cout("output.txt");

  string a;

  int cnt = 0;
  while (cin >> a) {
    for (auto i : a) {
      if (i == 'O') {
        cnt++;
      }
    }
  }

  cout << cnt << endl;
  return 0;
}