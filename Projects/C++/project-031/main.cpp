#define _USE_MATH_DEFINES
#include <algorithm>
#include <cmath>
#include <ctype.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
  ll i, j, k;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string textString;
  cin >> textString;

  string returnString = "";
  ll actualLength = textString.size() / 3;
  ll index = 0;

  for (index = 0; index < actualLength; index++) {
    ll firstIndex = index;
    ll secondIndex = index + actualLength;
    ll thirdIndex = index + actualLength * 2;

    if (textString[firstIndex] != textString[secondIndex] ||
        textString[secondIndex] != textString[thirdIndex]) {
      if (textString[firstIndex] == textString[secondIndex]) {
        returnString.push_back(textString[firstIndex]);
      } else if (textString[secondIndex] == textString[thirdIndex]) {
        returnString.push_back(textString[secondIndex]);
      } else {
        returnString.push_back(textString[firstIndex]);
      }
    } else {
      returnString.push_back(textString[firstIndex]);
    }
  }

  cout << returnString << "\n";

  return 0;
}
// Stop: Tue May 12 12:11:38 MDT 2020