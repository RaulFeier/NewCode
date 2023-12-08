#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

pair<i64, i64> check(string &ans, i64 i) {
  if (ans[i] == 'o') {
    if (ans[i + 1] == 'n' and i - 1 + 3 <= ans.size()) {
      if (ans[i + 2] == 'e') {
        return {1, 3};
      }
    }
  }
  if (ans[i] == 't' and i - 1 + 3 <= ans.size()) {
    if (ans[i + 1] == 'w') {
      if (ans[i + 2] == 'o') {
        return {2, 3};
      }
    }
  }
  if (ans[i] == 't' and i - 1 + 5 <= ans.size()) {
    if (ans[i + 1] == 'h') {
      if (ans[i + 2] == 'r') {
        if (ans[i + 3] == 'e') {
          if (ans[i + 4] == 'e') {
            return {3, 5};
          }
        }
      }
    }
  }
  if (ans[i] == 'f' and i - 1 + 4 <= ans.size()) {
    if (ans[i + 1] == 'o') {
      if (ans[i + 2] == 'u') {
        if (ans[i + 3] == 'r') {
          return {4, 4};
        }
      }
    }
  }
  if (ans[i] == 'f' and i - 1 + 4 <= ans.size()) {
    if (ans[i + 1] == 'i') {
      if (ans[i + 2] == 'v') {
        if (ans[i + 3] == 'e') {
          return {5, 4};
        }
      }
    }
  }
  if (ans[i] == 's' and i - 1 + 3 <= ans.size()) {
    if (ans[i + 1] == 'i') {
      if (ans[i + 2] == 'x') {
        return {6, 3};
      }
    }
  }
  if (ans[i] == 's' and i - 1 + 5 <= ans.size()) {
    if (ans[i + 1] == 'e') {
      if (ans[i + 2] == 'v') {
        if (ans[i + 3] == 'e') {
          if (ans[i + 4] == 'n') {
            return {7, 5};
          }
        }
      }
    }
  }
  if (ans[i] == 'e' and i - 1 + 5 <= ans.size()) {
    if (ans[i + 1] == 'i') {
      if (ans[i + 2] == 'g') {
        if (ans[i + 3] == 'h') {
          if (ans[i + 4] == 't') {
            return {8, 5};
          }
        }
      }
    }
  }
  if (ans[i] == 'n' and i - 1 + 4 <= ans.size()) {
    if (ans[i + 1] == 'i') {
      if (ans[i + 2] == 'n') {
        if (ans[i + 3] == 'e') {
          return {9, 4};
        }
      }
    }
  }

  return {0, 0};
}

int main() {
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};

  string ans;
  i64 total = 0;
  while (cin >> ans) {

    pair<i64, i64> a;
    int I;
    i64 aa = 0;
    for (i64 i = 0; i < ans.size(); i++) {
      if (ans[i] >= 48 and ans[i] <= 57) {
        aa = ans[i] - '0';
        I = i + 1;
        break;
      } else {
        a = check(ans, i);
        if (a.first != 0) {
          aa = a.first;
          I = a.second + i;
          break;
        }
      }
    }

    pair<i64, i64> b;
    int bb = 0;
    for (i64 i = I; i <= ans.size(); i++) {
      if (ans[i] >= 48 and ans[i] <= 57) {
        bb = ans[i] - '0';
      } else {
        b = check(ans, i);
        if (b.first != 0) {
          I = b.second + i - 1;
          bb = b.first;
        }
      }
    }

    i64 nr;
    if (bb == 0) {
      nr = aa * 10 + aa;
    } else {
      nr = aa * 10 + bb;
    }

    total += nr;
    cout << nr << endl;
  }

  cout << total << endl;
  return 0;
}
