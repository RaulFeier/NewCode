#include <bits/stdc++.h>

using namespace std;

int main() {
  int total_width;
  cin >> total_width;

  int n;
  cin >> n;
  
  int total = 0;
  for (int i = 0; i < n; i++) {
    int w, l;
    cin >> w >> l;
    int tt = w * l;
    total += tt;
  }

  cout << total / total_width << endl;

  return 0;
}

/*
2 * 3 = 6
1 * 4 = 4
2
2
4
4
2
---------- +
4 * a = 24
a = 6
*/
