#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream cin{"alinieri.in"};
  ofstream cout{"alinieri.out"};

  int n, p, d;
  cin >> n >> p >> d;

  vector<int> planets_rotation(n);

  for (int i : planets_rotation) {
    cin >> i;
  }

  return 0;
}