#include <bits/stdc++.h>

using namespace std;

int s, t, n;
int currentTime = s;

int solve(vector<int> &walks, vector<int> &drives, vector<int> &arrivals,
          int i) {
  if (i == n) {
    return 0;
  }

  currentTime += walks[i];

  int eep = currentTime % arrivals[i];
  if (eep != 0) {
    currentTime += arrivals[i] - eep;
  }

  currentTime += drives[i];

  return solve(walks, drives, arrivals, i + 1);
}

int main() {
  cin >> s >> t >> n;

  vector<int> walks(n + 1);
  vector<int> drives(n);
  vector<int> arrivals(n);

  for (int i = 0; i < n + 1; i++) {
    cin >> walks[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> drives[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> arrivals[i];
  }

  solve(walks, drives, arrivals, 0);

  currentTime += walks[n];

  if (currentTime > t) {
    cout << "no" << endl;
  } else {
    cout << "yes" << endl;
  }

  return 0;
}