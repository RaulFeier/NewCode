#include <bits/stdc++.h>

using namespace std;

int add(int a, int b) { return a + b; }

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> v(n);
  vector<int> A(n);


  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  cout << add(n, m) << endl;

  cout << "Hello, world!" << endl;

  return 0;
}
