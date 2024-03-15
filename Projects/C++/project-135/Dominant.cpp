#include <bits/stdc++.h>

using namespace std;

int main() {
  //   ifstream cin{"dominant.in"};
  //   ofstream cout{"dominant.out"};

  int n, x, y;
  cin >> n >> x >> y;

  vector<int> a(n);

  for (auto &c : a) {
    cin >> c;
  }

  return 0;
}

/*
1  1  1  2  1  2  2  2  1  2
 1,2   2,2   2,2   1,2   2,2
    3,4         3,4   3,4

1  1  1  2  1  2  2  2  1  2
1:1 1:2
*/