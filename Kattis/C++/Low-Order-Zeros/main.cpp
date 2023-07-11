#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0);
  cout.tie(0);

  vector<int> vec(1000001);
  long long a = 1;
  for (int i = 1; i <= 1000000; i++) {
    a *= i;
    while (a % 10 == 0) {
      a /= 10;
    }
    vec[i] = a % 10;
    a %= 10000000;
  }

  while (true) {
    int num;
    cin >> num;
    if (num == 0) {
      break;
    }
    cout << vec[num] << '\n';
  }

  return 0;
}