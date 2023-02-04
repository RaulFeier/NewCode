#include <bits/stdc++.h>

using namespace std;

/*
   _     _
  (c).-.(c)
   / ._. \
 __\( Y )/__
(_.-/'-'\-._)
   || R ||
 _.' `-' '._
(.-./`-`\.-.)
 `-'     `-'
*/

// char(92)

int main() {
  cout << "                 _     _  " << endl;
  cout << "                (c).-.(c) " << endl;
  cout << "                 / ._. " << char(92) << endl;
  cout << "               __" << char(92) << "( Y )/__" << endl;
  cout << "              (_.-/'-'" << char(92) << "-._)" << endl;
  cout << "                | Riana |     " << endl;
  cout << "               _.' `-' '._   " << endl;
  cout << "              (.-./`-`" << char(92) << ".-.)" << endl;
  cout << "               `-'     `-'   " << endl;

  double x, y, size = 10;
  string message(" Imi pare rau ");
  int print_line = 4;
  if (message.length() % 2 != 0)
    message += " ";

  for (x = 0; x < size; x++) {
    for (y = 0; y <= 4 * size; y++) {
      double dist1 = sqrt(pow(x - size, 2) + pow(y - size, 2));
      double dist2 = sqrt(pow(x - size, 2) + pow(y - 3 * size, 2));

      if (dist1 < size + 0.5 || dist2 < size + 0.5) {
        cout << "♥️";
      } else
        cout << " ";
    }
    cout << "\n";
  }

  for (x = 1; x < 2 * size; x++) {
    for (y = 0; y < x; y++)
      cout << " ";

    for (y = 0; y < 4 * size + 1 - 2 * x; y++) {
      if (x >= print_line - 1 && x <= print_line + 1) {
        int idx = y - (4 * size - 2 * x - message.length()) / 2;
        if (idx < message.length() && idx >= 0) {
          if (x == print_line)
            cout << message[idx];
          else
            cout << " ";
        } else
          cout << "♥️";
      } else
        cout << "♥️";
    }
    cout << endl;
  }
}