#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 n, k;
  cin >> n >> k;

  deque<i64> time(n);
  vector<bool> farmers(k, true);
  deque<i64> free_farmers;

  for (i64 i = 0; i < n; i++) {
    cin >> time[i];
    if (i < k) {
      free_farmers.push_back(i);
    }
  }

  priority_queue<pair<i64, i64>, vector<pair<i64, i64>>,
                 greater<pair<i64, i64>>>
      working;
  i64 general_time = 0;

  while (true) {
    while (!time.empty()) {
      while (!free_farmers.empty()) {
        i64 f = free_farmers.front();
        farmers[f] = 0;
        free_farmers.pop_front();
        i64 t = time.front();
        time.pop_front();
        working.push({t + general_time, f});
      }
    }

    if (time.empty()) {
      break;
    }

    general_time = working.top().first;

    while (general_time == working.top().first) {
      i64 f = working.top().second;
      working.pop();
      farmers[f] = 1;
      free_farmers.push_back(f);
    }
  }

  for (i64 i = 0; i < k; i++) {
    if (farmers[i] == 1) {
      cout << "1";
    } else {
      cout << "0";
    }
  }
  cout << endl;

  return 0;
}

/*
3 1 4159 2 6 5
*/