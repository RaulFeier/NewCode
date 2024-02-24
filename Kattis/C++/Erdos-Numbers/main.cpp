#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
using str = string;
#define endl '\n'

unordered_map<string, i64> bfs(unordered_map<string, vector<string>> &adj) {
  unordered_map<string, i64> dist;
  dist["PAUL_ERDOS"] = 0;

  queue<string> q;
  q.push("PAUL_ERDOS");

  while (!q.empty()) {
    auto crt = q.front();
    q.pop();

    for (auto &c : adj[crt]) {
      if (dist.count(c)) {
        if (dist[crt] + 1 < dist[c]) {
          dist[c] = dist[crt] + 1;
          q.push(c);
        }
      } else {
        dist[c] = dist[crt] + 1;
        q.push(c);
      }
    }
  }

  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  str s;

  unordered_map<str, vector<str>> list;
  vector<str> names;

  while (getline(cin, s)) {
    stringstream ss(s);
    str name;
    ss >> name;

    names.push_back(name);

    str x;
    while (ss >> x) {
      list[name].push_back(x);
      list[x].push_back(name);
    }
  }

  unordered_map<string, i64> m = bfs(list);

  for (auto &c : names) {
    if (m.count(c)) {
      cout << c << " " << m[c] << endl;
    } else {
      cout << c << " no-connection" << endl;
    }
  }

  return 0;
}

/*
PAUL_ERDOS = 0
HARVEY_ABBOTT = 1
JANOS_ACZEL = 2
TAKASHI_AGOH = 3
RON_AHARONI  = 4
MARTIN_AIGNER = 5
MIKLOS_AJTAI = 6
CHARLES_AULL = 7
EZRA_BROWN = 8
PAUL_DIERKER = 9
MATTS_ESSEN = 10
FRANK_BROWN = 11
CHARLES_ROGERS = 12
*/
