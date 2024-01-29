#include <bits/stdc++.h>

using namespace std;

class point {
public:
  int x, y, z;

  bool operator<(const point &p) const { return x < p.x; }
};

int main() {
  set<point> points;

  points.insert({1, 9, 5});
  points.insert({7, 3, 6});
  points.insert({0, 4, 2});
  points.insert({10, 8, 40});
  points.insert({5, 9, 31});

  for (auto &c : points) {
    cout << c.x << " " << c.y << " " << c.z << endl;
  }

  return 0;
}