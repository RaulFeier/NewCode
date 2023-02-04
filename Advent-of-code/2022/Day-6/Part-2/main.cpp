#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};

  string ans;
  cin >> ans;

  for (int i = 0; i < ans.size() - 13; i++) {
    set<char> s;
    for (int j = i; j < i + 14; j++) {
      s.insert(ans[j]);
    }
    if (s.size() == 14) {
      cout << i + 14 << endl;
      break;
    }
  }
}
