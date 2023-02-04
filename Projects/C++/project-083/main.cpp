#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream cin{"input.txt"};
  ofstream cout{"output.txt"};

  int n, h;
  cin >> n >> h;

  vector<int> v(h + 2);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (i % 2 == 0) {
      v[1] += 1;
      v[x + 1] -= 1;
    } else {
      v[h - x - 1] += 1;
    }
  }

  for (auto &e : v) {
    cout << e << " ";
  }

  cout << endl;

  return 0;
}

/*
1 2 2 2 3 3 3 3 3 3 3 4 4 4
*/