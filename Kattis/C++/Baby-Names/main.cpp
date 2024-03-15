#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

using i64 = int64_t;
typedef tree<string, null_type, less<string>, rb_tree_tag,
             tree_order_statistics_node_update>
    ost;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int type;

  ost treeb, treeg;

  while (true) {
    cin >> type;
    if (type == 0) {
      break;
    }

    if (type == 1) {
      string name;
      int gender;
      cin >> name >> gender;
      if (gender == 1) {
        treeb.insert(name);
      } else {
        treeg.insert(name);
      }
    } else if (type == 2) {
      string name;
      cin >> name;
      treeb.erase(name);
      treeg.erase(name);
    } else {
      string start, end;
      int gender;
      cin >> start >> end >> gender;

      i64 sol = 0;
      if (gender == 1 or gender == 0) {
        auto n = treeb.lower_bound(end);

        if (n != treeb.end()) {
          sol += treeb.order_of_key(*n);
        } else {
          sol += treeb.size();
        }

        n = treeb.lower_bound(start);

        if (n != treeb.end()) {
          sol -= treeb.order_of_key(*n);
        } else {
          sol -= treeb.size();
        }
      }

      if (gender == 2 or gender == 0) {
        auto n = treeg.lower_bound(end);

        if (n != treeg.end()) {
          sol += treeg.order_of_key(*n);
        } else {
          sol += treeg.size();
        }

        n = treeg.lower_bound(start);

        if (n != treeg.end()) {
          sol -= treeg.order_of_key(*n);
        } else {
          sol -= treeg.size();
        }
      }

      cout << sol << '\n';
    }
  }

  return 0;
}

/*
female:
Kattisjr

male:
oliver
simba
*/