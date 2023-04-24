#include <bits/stdc++.h>

using namespace std;

int solve(vector<string> &lines) {
  pair<int, int> eep;
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[i].size(); j++) {
      if (lines[i][j] == 'W') {
        eep = {i, j};
        break;
      }
    }
  }

  int cnt = 0;

  if (lines[eep.first - 1][eep.second - 1] == 'O') {
    cnt++;
  }
  if (lines[eep.first - 1][eep.second + 1] == 'O') {
    cnt++;
  }
  if (lines[eep.first][eep.second + 2] == 'O') {
    cnt++;
  }
  if (lines[eep.first][eep.second - 2] == 'O') {
    cnt++;
  }
  if (lines[eep.first + 1][eep.second - 1] == 'O') {
    cnt++;
  }
  if (lines[eep.first + 1][eep.second + 1] == 'O') {
    cnt++;
  }

  return cnt;
}

int main() {
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};

  int tc;
  cin >> tc;

  string ans;
  cin.get();
  getline(cin, ans);

  vector<string> lines;
  while (tc--) {
    while (getline(cin, ans)) {
      if (ans == "") {
        break;
      } else {
        lines.push_back(ans);
      }
    }
    cout << solve(lines) << endl;
    lines.clear();
  }
  return 0;
}