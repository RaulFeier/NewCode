#include <bits/stdc++.h>
#include <cstdint>

using namespace std;
using i16 = int16_t;

class pulsar {
public:
  i16 x;
  i16 y;
  i16 r;
  i16 t;
};

const vector<int> dir_x = {1, -1, 0, 0};
const vector<int> dir_y = {0, 0, -1, 1};

i16 solve1(i16 n, i16 p, vector<pulsar> &pulsari) { return 1; }

i16 solve2(i16 line, i16 p, vector<pulsar> &pulsari, pair<i16, i16> start,
           pair<i16, i16> end) {

  vector<vector<i16>> matrix(line, vector<i16>(line, 0));

  for (int i = 0; i < p; i++) {
    matrix[pulsari[i].x][pulsari[i].y] = 1;
  }

  return 1;
}

int main() {
  ifstream cin{"pulsar.in"};
  ofstream cout{"pulsar.out"};

  char c;
  i16 n, p;
  cin >> c >> n >> p;

  vector<pulsar> pulsari(p);
  for (i16 i = 0; i < p; i++) {
    cin >> pulsari[i].x >> pulsari[i].y >> pulsari[i].r >> pulsari[i].t;
  }

  pair<i16, i16> start;
  pair<i16, i16> end;

  cin >> start.first >> start.second;
  cin >> end.first >> end.second;

  if (c == '1') {
    cout << solve1(n, p, pulsari) << endl;
  } else if (c == '2') {
    cout << solve2(n, p, pulsari, start, end) << endl;
  }

  return 0;
}