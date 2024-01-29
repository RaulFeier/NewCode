#include <bits/stdc++.h>

using namespace std;

int main() {
  map<string, vector<string>> s;

  s["Raul"] = {"Maria", "Mihai", "Ionela"};
  s["Riana"] = {"Roberta", "Crist", "Razvan"};

  for (auto &c : s["Raul"]) {
    cout << c << endl;
  }

  return 0;
}