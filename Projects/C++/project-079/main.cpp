#include <bits/stdc++.h>

using namespace std;

int main() {
  ofstream cout{"output.txt"};
  cout << "M";
  for (int i = 0; i < 1000000; i++) {
    cout << "A";
    if (i % 10000 == 0) {
      cout << endl;
    }
  }
}