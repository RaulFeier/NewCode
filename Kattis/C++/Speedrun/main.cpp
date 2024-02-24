#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class job {
public:
  int index, start, end;

  bool operator<(job cnt) const { return end < cnt.end; }
};

int solve(vector<job> &jobs) {
  sort(jobs.begin(), jobs.end());
  set<int> s;
  i64 nr = 0;

  for (i64 i = jobs.size() - 1; i >= 0; i--) {
    int t = jobs[i].end - (i ? jobs[i - 1].end : 0);

    s.insert(jobs[i].start);

    while (!s.empty() and t) {
      auto it = s.begin();
      if (*it <= t) {
        t -= *it;
        nr++;
      } else {
        s.insert(*it - t);
        t = 0;
      }
      s.erase(it);
    }
  }

  return nr;
}

int main() {
  int g, n;
  cin >> g >> n;

  vector<job> jobs(n);

  for (i64 i = 0; i < n; i++) {
    jobs[i].index = i;
    cin >> jobs[i].start >> jobs[i].end;
    jobs[i].start = jobs[i].end - jobs[i].start;
  }

  if (solve(jobs) >= g) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}

/*
0 20
19 21
20 24000
*/