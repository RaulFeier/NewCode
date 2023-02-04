#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<char> v;
  for (int i = 0; i < n; i++) {
    char p;
    cin >> p;
    v.push_back(p);
  }

  if (v.size() % 2 == 0) {
    cout << v.size() / 2 << endl;
  } else {
    cout << v.size() / 2 + 1 << endl;
  }
}