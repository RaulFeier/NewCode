#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> restore_array(int n, std::vector<int> &b) {
  std::vector<int> a(n);

  for (int i = n - 1; i >= 0; i--) {
    a[i] = b.back();
    b.pop_back();
    for (int j = i + 1; j < n; j++) {
      a[i] = std::min(a[i], a[j]);
    }
  }

  return a;
}

int main() {
  int t;
  std::cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    std::cin >> n;

    std::vector<int> b(n * (n - 1) / 2);
    for (int j = 0; j < b.size(); j++) {
      std::cin >> b[j];
    }

    std::vector<int> a = restore_array(n, b);

    for (int j = 0; j < n; j++) {
      std::cout << a[j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
