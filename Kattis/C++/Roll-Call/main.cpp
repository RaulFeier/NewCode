#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

class person {
public:
  string first;
  string last;
};

bool compare(person *p1, person *p2) {
  if (p1->last == p2->last) {
    return p1->first < p2->first;
  }
  return p1->last < p2->last;
}

int main() {
  vector<person *> v;
  string first, last;

  unordered_map<string, int> names;

  while (cin >> first && cin >> last) {
    person *p = new person;
    p->first = first;
    p->last = last;
    v.push_back(p);

    names[first]++;
  }

  sort(v.begin(), v.end(), compare);

  for (auto i : v) {
    cout << i->first;
    if (names[i->first] > 1) {
      cout << " " << i->last;
    }
    cout << endl;
  }
}