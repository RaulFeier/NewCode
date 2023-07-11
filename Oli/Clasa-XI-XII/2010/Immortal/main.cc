#include <bits/stdc++.h>
#include <fstream>

using namespace std;

class lupte {
public:
  short cordx1, cordy1;
  short cordx2, cordy2;
};

vector<lupte> Lupte(21, {0, 0, 0, 0});

const vector<short> dirx = {1, -1, 0, 0};
const vector<short> diry = {0, 0, -1, 1};

bool inside(short xx, short yy, vector<vector<short>> &v) {
  return 0 <= xx and xx < v.size() and 0 <= yy and yy < v[0].size();
}

void solve(vector<vector<short>> &v, short index) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  ifstream cin("immortal.in");
  ofstream cout("immortal.out");
  short gasit = 0;

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[0].size(); j++) {
      if (v[i][j]) {
        gasit++;
        for (int c = 0; c < 4; c++) {
          short xx = i + dirx[c];
          short yy = j + diry[c];
          if (inside(xx, yy, v) and v[xx][yy]) {
            short xx2 = xx + dirx[c];
            short yy2 = yy + diry[c];

            if (inside(xx2, yy2, v) and !v[xx2][yy2]) {
              v[i][j] = 0;
              v[xx][yy] = 0;
              v[xx2][yy2] = 1;
              lupte eep;
              eep.cordx1 = i, eep.cordy1 = j, eep.cordx2 = xx2,
              eep.cordy2 = yy2;
              Lupte[index] = eep;
              solve(v, index + 1);
              v[i][j] = 1;
              v[xx][yy] = 1;
              v[xx2][yy2] = 0;
            }
          }
        }
      }
    }
  }

  if (gasit == 1) {
    for (auto &x : Lupte) {
      if (x.cordx1 == 0 and x.cordy1 == 0 and x.cordx2 == 0 and x.cordy2 == 0) {
        break;
      }
      cout << x.cordx1 + 1 << ' ' << x.cordy1 + 1 << ' ' << x.cordx2 + 1 << ' '
           << x.cordy2 + 1 << '\n';
    }

    exit(0);
  }
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  ifstream cin("immortal.in");
  ofstream cout("immortal.out");

  short n, m, i;
  cin >> n >> m >> i;

  vector<vector<short>> v(n, vector<short>(m, 0));

  for (int tc = 0; tc < i; tc++) {
    short x, y;
    cin >> x >> y;
    x--;
    y--;
    v[x][y] = 1;
  }

  solve(v, 0);
  return 0;
}
