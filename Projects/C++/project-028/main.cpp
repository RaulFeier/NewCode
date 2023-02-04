#include <bits/stdc++.h>

using namespace std;

int main() {
  int a1, a2, b1, b2;
  while (cin >> a1 >> a2 >> b1 >> b2) {
    if (a1 == 0) {
      break;
    }
    int points1 = max(a1, a2) * 10 + min(a1, a2);
    int points2 = max(b1, b2) * 10 + min(b1, b2);

    if (points1 == 21 && points2 == 21) {
      cout << "Tie." << endl;
    } else if (points1 == 21) {
      cout << "Player 1 wins." << endl;
    } else if (points2 == 21) {
      cout << "Player 2 wins." << endl;
    } else if (points1 % 10 == points1 / 10 && points2 % 10 == points2 / 10) {
      if (points1 > points2) {
        cout << "Player 1 wins." << endl;
      } else if (points2 > points1) {
        cout << "Player 2 wins." << endl;
      } else {
        cout << "Tie." << endl;
      }
    } else if (points1 % 10 == points1 / 10) {
      cout << "Player 1 wins." << endl;
    } else if (points2 % 10 == points2 / 10) {
      cout << "Player 2 wins." << endl;
    } else if (points1 > points2) {
      cout << "Player 1 wins." << endl;
    } else if (points2 > points1) {
      cout << "Player 2 wins." << endl;
    } else {
      cout << "Tie." << endl;
    }
  }
  return 0;
}