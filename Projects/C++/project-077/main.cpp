#include <bits/stdc++.h>

using namespace std;

int main() {
  //   ifstream cin{"input.txt"};
  //   ofstream cout{"output.txt"};

  int n;
  cin >> n;
  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  vector<int> t = v;

  int max = 0;
  while (true) {
    int a = v[n - 1], l = 0, r = n - 1;
    bool ok = true;

    while (ok && l <= r) {
      int mid = l + ((r - l) / 2);

      if (t[mid] == a) {
        swap(v[n - 1], v[mid - 1]);
        ok = false;
      } else if (t[mid] < a) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    int sum = v[n - 1] * v[0];

    for (int i = 0; i < n - 1; i++) {
      sum += v[i] * v[i + 1];
    }

    if (max < sum) {
      max = sum;
    } else {
      break;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  return 0;
}