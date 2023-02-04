#include <iostream>

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;

  bool ans = false;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a <= d) {
      ans = true;
      cout << "It hadn't snowed this early in " << i << " years!" << endl;
      break;
    }
  }
  if (!ans) {
  }
}