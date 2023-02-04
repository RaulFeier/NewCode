#include <cstdio>
#include <fstream>

using namespace std;

ifstream cin("bac.txt");

int main() {
  int x, y, n0 = -1, n, res = 0;
  cin >> x >> y;

  while (cin >> n) {
    if (n0 != n && n >= x && n <= y) {
      res++;
    }

    n0 = n;
  }

  printf("%d\n", res);

  return 0;
}