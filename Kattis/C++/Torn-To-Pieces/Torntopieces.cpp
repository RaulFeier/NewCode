#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

map<string, string> path;

bool dfs(string node, cc_hash_table<string, set<string>> &h, string &end,
         string &start) {
  queue<string> q;
  q.push(start);

  while (!q.empty()) {
    auto crt = q.front();
    q.pop();

    for (auto &c : h[crt]) {
      if (path.count(c) == 0) {
        path[c] = crt;
        q.push(c);
      }
    }
  }

  return false;
}

int main() {
  int n;
  cin >> n;

  cc_hash_table<string, set<string>> h;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    cin.get();
    string str;
    getline(cin, str);

    stringstream ss(str);
    string word;

    while (ss >> word) {
      h[s].insert(word);
      h[word].insert(s);
    }
  }

  string start, end;
  cin >> start >> end;

  dfs(start, h, end, start);

  if (path.count(end) == 0) {
    cout << "no route found" << endl;
  } else {
    vector<string> end_path;
    while (end != start) {
      end_path.push_back(end);
      end = path[end];
    }
    end_path.push_back(end);

    for (int i = end_path.size() - 1; i >= 0; i--) {
      cout << end_path[i] << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
4
1 2
2 1 3
5 4 6
6 5

1 -> 5

*/