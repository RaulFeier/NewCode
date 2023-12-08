#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};

  string ans;
  i64 total = 0;
  while (cin >> ans) {

    int a;
    for (i64 i = 0; i < ans.size(); i++) {
      if (ans[i] >= 48 and ans[i] <= 57) {
        a = ans[i] - '0';
        break;
      }
    }

    int b;
    for (i64 i = ans.size() - 1; i >= 0; i--) {
      if (ans[i] >= 48 and ans[i] <= 57) {
        b = ans[i] - '0';
        break;
      }
    }

    i64 nr = a * 10 + b;

    total += nr;
  }

  cout << total << endl;
  return 0;
}
