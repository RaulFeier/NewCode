#include <bits/stdc++.h>

using namespace std;

int bb = 00;

void left(vector<int> &a) {
  int t = 0;
  for (int i = 0; i < 4; i++) {
    t++;
  }
}

int max(int a, int b) {
  int v;
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

bool check(int x) {
  if (x % 2 == 0) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int a;

  vector<int> b = {1, 2, 4};

  for (auto &x : b) {
    if (check(x)) {
      cout << "avem" << endl;
    }
  }

  return 0;
}