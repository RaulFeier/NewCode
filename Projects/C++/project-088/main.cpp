#include <bits/stdc++.h>

using namespace std;

int main() {
  map<string, int> m;

  vector<string> v = {"eep", "Riana", "eep", "Raul", "eep", "Riana"};

  for (int i = 0; i < v.size(); i++) {
    m[v[i]]++;
  }

  for (auto it = m.begin(); it != m.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }

  return 0;
}