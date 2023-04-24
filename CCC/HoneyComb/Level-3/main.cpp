#include <bits/stdc++.h>

using namespace std;

const vector<int> dirx = {-1, -1, 0, 0, 1, 1};
const vector<int> diry = {-1, 1, 2, -2, 1, -1};

string solve(vector<string> &lines) {
  pair<int, int> eep;
  for (int i = 0; i < lines.size(); i++) {
    for (int j = 0; j < lines[i].size(); j++) {
      if (lines[i][j] == 'W') {
        eep = {i, j};
        break;
      }
    }
  }

  for (int xx = 0; xx < 6; xx++) {
    int ii = eep.first + dirx[xx];
    int jj = eep.second + diry[xx];
    while (true) {
      if (lines[ii][jj] == 'X') {
        break;
      }

      if ((ii == 0 or ii == lines.size() - 1 or jj == 0 or
           jj == lines.front().size() - 1) and
          lines[ii][jj] == 'O') {
        return "FREE";
      }

      if (lines[ii][jj] == 'O') {
        ii += dirx[xx];
        jj += diry[xx];
      }
    }
  }

  return "TRAPPED";
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
}