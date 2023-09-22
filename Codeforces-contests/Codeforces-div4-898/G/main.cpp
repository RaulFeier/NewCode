#include <iostream>
#include <string>

using namespace std;

int maxCoins(string s) {
  int coins = 0;

  while (true) {
    bool found = false;

    for (int i = 0; i < s.length() - 1; ++i) {
      if (s[i] == 'A' && s[i + 1] == 'B') {
        s[i] = 'B';
        s[i + 1] = 'C';
        coins++;
        found = true;
      } else if (s[i] == 'B' && s[i + 1] == 'A') {
        s[i] = 'C';
        s[i + 1] = 'B';
        coins++;
        found = true;
      }
    }

    if (!found) {
      break;
    }
  }

  return coins;
}

int main() {
  int n;
  cin >> n;
  cin.ignore();

  for (int i = 0; i < n; ++i) {
    string s;
    getline(cin, s);
    int result = maxCoins(s);
    cout << result << endl;
  }

  return 0;
}
