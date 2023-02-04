#include <bits/stdc++.h>

using namespace std;

vector<int> dirx = {-1, 0, 1, 0};
vector<int> diry = {0, 1, 0, -1};

short solve1(short &n, short &g, vector<vector<short>> &eep) {
  short cnt[n][n];
  memset(cnt, -1, sizeof(cnt));

  deque<pair<short, short>> q;
  pair<short, short> crt = {0, 0};
  q.push_back(crt);

  cnt[0][0] = 0;

  while (!q.empty()) {
    crt = q.front();
    q.pop_front();

    for (short i = 0; i < 4; i++) {
      short ii = crt.first + dirx[i];
      short jj = crt.second + diry[i];
      if ((ii >= 0) and (ii < n) and (jj >= 0) and (jj < n) and
          cnt[ii][jj] == -1) {
        if (eep[ii][jj] < g) {
          cnt[ii][jj] = cnt[crt.first][crt.second] + 1;
          q.push_back({ii, jj});
        } else {
          cnt[ii][jj] = cnt[crt.first][crt.second];
          q.push_front({ii, jj});
        }
      }
    }
  }

  return cnt[n - 1][n - 1];
}

bool bfs(short &value, short &n, vector<vector<short>> &eep) {
  short cnt[n][n];
  memset(cnt, -1, sizeof(cnt));

  deque<pair<short, short>> q;
  pair<short, short> crt = {0, 0};
  q.push_back(crt);

  cnt[0][0] = 0;

  while (!q.empty()) {
    crt = q.front();
    q.pop_front();

    for (short i = 0; i < 4; i++) {
      short ii = crt.first + dirx[i];
      short jj = crt.second + diry[i];
      if ((ii >= 0) and (ii < n) and (jj >= 0) and (jj < n) and
          cnt[ii][jj] == -1) {
        if (eep[ii][jj] >= value) {
          cnt[ii][jj] = cnt[crt.first][crt.second] + 1;
          q.push_back({ii, jj});
        }
      }
    }
  }

  return (cnt[n - 1][n - 1] != -1);
}

short solve2(short &n, vector<vector<short>> &eep) {
  short left = 0, right = 10000, sol;
  while (left <= right) {
    short mid = (left + right) / 2;
    if (bfs(mid, n, eep)) {
      sol = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return sol;
}

int main() {
  ifstream cin("rover.in");
  ofstream cout("rover.out");

  char cerinta;
  cin >> cerinta;

  short n;
  cin >> n;

  if (cerinta == '1') {
    short g;
    cin >> g;

    vector<vector<short>> eep(n, vector<short>(n));
    for (short i = 0; i < n; i++) {
      for (short j = 0; j < n; j++) {
        cin >> eep[i][j];
      }
    }
    cout << solve1(n, g, eep) << endl;
  } else {
    vector<vector<short>> eep(n, vector<short>(n));
    for (short i = 0; i < n; i++) {
      for (short j = 0; j < n; j++) {
        cin >> eep[i][j];
      }
    }
    cout << solve2(n, eep) << endl;
  }
}