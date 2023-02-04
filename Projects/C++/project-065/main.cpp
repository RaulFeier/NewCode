#include <bits/stdc++.h>

using namespace std;

int prim(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

int factori(int n) {
  int a[100];
  int k = 0;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      a[k] = i;
      k++;
    }
  }

  for (int i = 0; i < k; i++) {
    cout << a[i] << " ";
  }
}

int main() {
  int n;
  cin >> n;

  if (!prim(n)) {
    factori(n);
  }
}