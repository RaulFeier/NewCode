#include <cmath>
#include <iostream>

using namespace ::std;

int main() {
  int n, advance = 0, limit = 4, pos = 20, play;
  bool found = false;
  cin >> n;

  for (int i = 0; i < min(limit, n); i++) {
    cin >> play;
    advance += play;

    if (advance >= 10) {
      advance = 0;
      limit = i + 5;
    }

    pos += play;

    if (pos <= 0) {
      cout << "Safety" << endl;
      found = true;
      break;
    } else if (pos >= 100) {
      cout << "Touchdown" << endl;
      found = true;
      break;
    }
  }

  if (!found) {
    cout << "Nothing" << endl;
  }
  return 0;
}