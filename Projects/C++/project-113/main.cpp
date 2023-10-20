#include <bits/stdc++.h>

using namespace std;

int main() {
  string ans;
  
  vector<string> first_row;
  vector<string> second_row;

  while (getline(cin, ans)) {
    string eep = "";
    bool check = false;
    for (int i = 0; i < ans.size(); i++) {
      if (check) {
        eep += ans[i];
        if (i == ans.size() - 1) {
          second_row.push_back(eep);
        }
      }  

      if (ans[i] == '|') {
        first_row.push_back(eep);
        eep = "";
        check = true;
      } else {
        eep += ans[i];
      }
    }
  }

  for (auto &x : first_row) {
    cout << x;
  }

  cout << " " << endl;

  for (auto &x : second_row) {
    cout << x;
  }

  cout << endl;

  return 0;
}
