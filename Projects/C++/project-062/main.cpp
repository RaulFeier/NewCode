#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream f{"eep.txt"};
  while (!f.eof()) {
    string s;
    getline(f, s);
    cout << s << endl;
  }
}