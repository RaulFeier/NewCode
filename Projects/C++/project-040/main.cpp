#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<string> a;
  a.push_back("banana");
  a.push_back("apple");
  a.push_back("maria");
  a.push_back("feier");

  sort(a.begin(), a.end());
  for (auto x : a) {
    cout << x << endl;
  }
}
