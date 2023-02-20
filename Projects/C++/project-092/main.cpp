#include <bits/stdc++.h>

using namespace std;

struct elev {
  vector<int> note;
  bool corigent;
  int nr_catalog;
};

int main() {
  vector<elev> eep;

  elev a;

  a.note = {7, 8, 9, 10};
  a.corigent = false;
  a.nr_catalog = 3;

  eep.push_back(a);

  return 0;
}