#include <bits/stdc++.h>

using namespace std;

class point {
public:
  int from, to, res;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ifstream cin{"parcare.in"};
  ofstream cout{"parcare.out"};

  int n, m, t;
  cin >> n >> m >> t;

  vector<point> v(m);
  vector<int> oi;
  vector<int> ci;
  queue<int> q;

  if (n > m) {
    for (int i = 0; i < n; i++) {
      if (i < m) {
        cin >> v[i].from >> v[i].to;
        v[i].res = -1;
        oi.push_back(i);
        ci.push_back(i);
      }
      q.push(i); // we push all the parking spots
    }
  } else {
    for (int i = 0; i < m; i++) {
      cin >> v[i].from >> v[i].to;
      v[i].res = -1;
      oi.push_back(i);
      ci.push_back(i);
      if (i < n) {
        q.push(i); // we push all the parking spots
      }
    }
  }

  vector<int32_t> ans(n, -1);
  sort(oi.begin(), oi.end(),
       [&v](int a, int b) { return v[a].from < v[b].from; });
  sort(ci.begin(), ci.end(), [&v](int a, int b) { return v[a].to < v[b].to; });

  int32_t time = 1;
  int op = 0;
  int cl = 0;

  while (time <= t) {
    if (v[ci[cl]].to == time) {
      if (v[ci[cl]].res != -1) { // we check if we took a parking spot
        q.push(v[ci[cl]].res);   // if leave this parking spot open
        ans[v[ci[cl]].res] = -1;
      }
      cl++;
    }

    if (v[oi[op]].from == time) {
      if (!q.empty()) {
        v[oi[op]].res = q.front(); // we have a parking spot
        ans[q.front()] = time;     // the time we arrive at the parking spot
        q.pop();                   // the parking spot is now used
      }
      op++;
    }

    time++;
  }

  for (auto &c : v) {
    if (c.res != -1) {
      cout << c.res + 1 << endl;
    } else {
      cout << -1 << endl;
    }
  }

  for (auto &c : ans) {
    cout << c << " ";
  }
  cout << endl;

  return 0;
}

/*


1 7
2 6
3 5
*/