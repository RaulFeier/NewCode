#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

char reverse_caps(char x) {
  if (islower(x)) {
    return toupper(x);
  } else {
    return tolower(x);
  }
}

int main() {
  ifstream cin{"caps.in"};
  ofstream cout{"caps.out"};
  int k, q;
  string ans;

  cin >> k >> q;
  cin >> ans;

  string eep = ans;
  for (auto &x : eep) {
    x = reverse_caps(x);
  }
  vector<int> freq1(52, 0);
  vector<int> freq2(52, 0);

  for (auto &x : ans) {
    if (islower(x)) {
      freq1[x - 'a']++;
      freq2[x - 'a' + 26]++;
    } else {
      freq1[x - 'A']++;
      freq2[x - 'A' + 26]++;
    }
  }

  while (q--) {
    i64 n;
    cin >> n;
    n--;
  }
}