#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 total = 0;

void solve(string &dir, i64 index, map<string, pair<string, string>> &m,
           string &eep) {
  total++;
  if (index == dir.size()) {
    index = 0;
  }
  if (dir[index] == 'R') {
    if (m[eep].second == "ZZZ") {
      return;
    }
    solve(dir, ++index, m, m[eep].second);

  } else {
    if (m[eep].first == "ZZZ") {
      return;
    }
    solve(dir, ++index, m, m[eep].first);
  }
}

int main() {
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};

  string dir;
  cin >> dir;

  string s;
  map<string, pair<string, string>> m;
  cin.get();

  while (getline(cin, s)) {
    string key;
    key = s.substr(0, 3);

    pair<string, string> value = {s.substr(7, 3), s.substr(12, 3)};

    m[key] = value;
  }

  string start = "AAA";
  solve(dir, 0, m, start);

  cout << total << endl;

  return 0;
}