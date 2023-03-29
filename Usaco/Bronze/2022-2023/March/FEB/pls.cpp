#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  // calculate the original excitement level
  int original_level = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1] && s[i] != 'F') {
      original_level++;
    }
  }

  // find all possible excitement levels by replacing F with B or E
  set<int> excitement_levels;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'F') {
      s[i] = 'B';
      int level = 0;
      for (int j = 1; j < n; j++) {
        if (s[j] == s[j - 1] && s[j] != 'F') {
          level++;
        }
      }
      excitement_levels.insert(level);
      s[i] = 'E';
      level = 0;
      for (int j = 1; j < n; j++) {
        if (s[j] == s[j - 1] && s[j] != 'F') {
          level++;
        }
      }
      excitement_levels.insert(level);
      s[i] = 'F'; // reset to original value
    }
  }

  // output the results
  cout << excitement_levels.size() << endl;
  for (auto level : excitement_levels) {
    cout << original_level + level << endl;
  }

  return 0;
}
