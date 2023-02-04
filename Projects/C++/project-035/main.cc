#include <iostream>

using namespace std;

void backtraking(int v[], int m, int n) {
  for (int i = 0; i < m; i++) {
    cout << v[i] << " ";
  }
}

int main() {
  int m, n;
  cin >> m >> n;

  int v[m];

  backtraking(v, m, n);
}