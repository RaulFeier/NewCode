#include <bits/stdc++.h>

using namespace std;

int main() {
  map<string, int> eep;

  eep["Re"] = 1;
  eep["Te"] = 2;
  eep["He"] = 3;

  map<string, int>::iterator it = eep.begin();

  cout << it->first << endl;
  it++;
  cout << it->first << endl;
}