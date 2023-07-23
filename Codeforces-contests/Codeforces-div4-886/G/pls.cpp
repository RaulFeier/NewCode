#include <iostream>
#include <vector>
using namespace std;

int count_compass_pairs(const vector<pair<int, int>> &points) {
  int n = points.size();
  vector<int> directions(8, 0);

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int dx = points[j].first - points[i].first;
      int dy = points[j].second - points[i].second;

      if (dx == 0 || dy == 0) {
        continue; // Ignore points on the same horizontal or vertical line
      }

      if (dx * dy < 0) {
        if (dx > 0) {
          if (dy > 0)
            directions[0]++;
          else
            directions[1]++;
        } else {
          if (dy > 0)
            directions[2]++;
          else
            directions[3]++;
        }
      } else {
        if (dx > 0) {
          if (dy > 0)
            directions[4]++;
          else
            directions[5]++;
        } else {
          if (dy > 0)
            directions[6]++;
          else
            directions[7]++;
        }
      }
    }
  }

  int total_pairs = 0;
  for (int i = 0; i < 8; i++) {
    total_pairs += directions[i] * (directions[i] - 1) / 2;
  }

  return total_pairs;
}

int main() {
  int t;
  cin >> t; // Number of test cases

  for (int test_case = 0; test_case < t; test_case++) {
    int n;
    cin >> n; // Number of points in this test case
    vector<pair<int, int>> points;

    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      points.push_back(make_pair(x, y));
    }

    int result = count_compass_pairs(points);
    cout << result << endl;
  }

  return 0;
}
