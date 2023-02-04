#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 t;
  cin >> t;

  vector<char> v;
  for (i64 i = 0; i < t; i++) {
    string ans;
    getline(cin, ans);
    if (i == 0) {
      getline(cin, ans);
    }

    for (i64 j = 0; j < ans.size(); j++) {
      if (j == 0) {
        if (ans[j] == 'a') {
          v.push_back('2');
        } else if (ans[j] == 'b') {
          v.push_back('2');
          v.push_back('2');
        } else if (ans[j] == 'c') {
          v.push_back('2');
          v.push_back('2');
          v.push_back('2');
        } else if (ans[j] == 'd') {
          v.push_back('3');
        } else if (ans[j] == 'e') {
          v.push_back('3');
          v.push_back('3');
        } else if (ans[j] == 'f') {
          v.push_back('3');
          v.push_back('3');
          v.push_back('3');
        } else if (ans[j] == 'g') {
          v.push_back('4');
        } else if (ans[j] == 'h') {
          v.push_back('4');
          v.push_back('4');
        } else if (ans[j] == 'i') {
          v.push_back('4');
          v.push_back('4');
          v.push_back('4');
        } else if (ans[j] == 'j') {
          v.push_back('5');
        } else if (ans[j] == 'k') {
          v.push_back('5');
          v.push_back('5');
        } else if (ans[j] == 'l') {
          v.push_back('5');
          v.push_back('5');
          v.push_back('5');
        } else if (ans[j] == 'm') {
          v.push_back('6');
        } else if (ans[j] == 'n') {
          v.push_back('6');
          v.push_back('6');
        } else if (ans[j] == 'o') {
          v.push_back('6');
          v.push_back('6');
          v.push_back('6');
        } else if (ans[j] == 'p') {
          v.push_back('7');
        } else if (ans[j] == 'q') {
          v.push_back('7');
          v.push_back('7');
        } else if (ans[j] == 'r') {
          v.push_back('7');
          v.push_back('7');
          v.push_back('7');
        } else if (ans[j] == 's') {
          v.push_back('7');
          v.push_back('7');
          v.push_back('7');
          v.push_back('7');
        } else if (ans[j] == 't') {
          v.push_back('8');
        } else if (ans[j] == 'u') {
          v.push_back('8');
          v.push_back('8');
        } else if (ans[j] == 'v') {
          v.push_back('8');
          v.push_back('8');
          v.push_back('8');
        } else if (ans[j] == 'w') {
          v.push_back('9');
        } else if (ans[j] == 'x') {
          v.push_back('9');
          v.push_back('9');
        } else if (ans[j] == 'y') {
          v.push_back('9');
          v.push_back('9');
          v.push_back('9');
        } else if (ans[j] == 'z') {
          v.push_back('9');
          v.push_back('9');
          v.push_back('9');
          v.push_back('9');
        } else if (ans[j] == ' ') {
          v.push_back('0');
        }

      } else {
        if (ans[j] == 'a') {
          if (ans[j - 1] == 'a' || ans[j - 1] == 'b' || ans[j - 1] == 'c') {
            v.push_back(' ');
          }
          v.push_back('2');
        } else if (ans[j] == 'b') {
          if (ans[j - 1] == 'a' || ans[j - 1] == 'b' || ans[j - 1] == 'c') {
            v.push_back(' ');
          }
          v.push_back('2');
          v.push_back('2');
        } else if (ans[j] == 'c') {
          if (ans[j - 1] == 'a' || ans[j - 1] == 'b' || ans[j - 1] == 'c') {
            v.push_back(' ');
          }
          v.push_back('2');
          v.push_back('2');
          v.push_back('2');
        } else if (ans[j] == 'd') {
          if (ans[j - 1] == 'd' || ans[j - 1] == 'e' || ans[j - 1] == 'f') {
            v.push_back(' ');
          }
          v.push_back('3');
        } else if (ans[j] == 'e') {
          if (ans[j - 1] == 'd' || ans[j - 1] == 'e' || ans[j - 1] == 'f') {
            v.push_back(' ');
          }
          v.push_back('3');
          v.push_back('3');
        } else if (ans[j] == 'f') {
          if (ans[j - 1] == 'd' || ans[j - 1] == 'e' || ans[j - 1] == 'f') {
            v.push_back(' ');
          }
          v.push_back('3');
          v.push_back('3');
          v.push_back('3');
        } else if (ans[j] == 'g') {
          if (ans[j - 1] == 'g' || ans[j - 1] == 'h' || ans[j - 1] == 'i') {
            v.push_back(' ');
          }
          v.push_back('4');
        } else if (ans[j] == 'h') {
          if (ans[j - 1] == 'g' || ans[j - 1] == 'h' || ans[j - 1] == 'i') {
            v.push_back(' ');
          }
          v.push_back('4');
          v.push_back('4');
        } else if (ans[j] == 'i') {
          if (ans[j - 1] == 'g' || ans[j - 1] == 'h' || ans[j - 1] == 'i') {
            v.push_back(' ');
          }
          v.push_back('4');
          v.push_back('4');
          v.push_back('4');
        } else if (ans[j] == 'j') {
          if (ans[j - 1] == 'j' || ans[j - 1] == 'k' || ans[j - 1] == 'l') {
            v.push_back(' ');
          }
          v.push_back('5');
        } else if (ans[j] == 'k') {
          if (ans[j - 1] == 'j' || ans[j - 1] == 'k' || ans[j - 1] == 'l') {
            v.push_back(' ');
          }
          v.push_back('5');
          v.push_back('5');
        } else if (ans[j] == 'l') {
          if (ans[j - 1] == 'j' || ans[j - 1] == 'k' || ans[j - 1] == 'l') {
            v.push_back(' ');
          }
          v.push_back('5');
          v.push_back('5');
          v.push_back('5');
        } else if (ans[j] == 'm') {
          if (ans[j - 1] == 'm' || ans[j - 1] == 'n' || ans[j - 1] == 'o') {
            v.push_back(' ');
          }
          v.push_back('6');
        } else if (ans[j] == 'n') {
          if (ans[j - 1] == 'm' || ans[j - 1] == 'n' || ans[j - 1] == 'o') {
            v.push_back(' ');
          }
          v.push_back('6');
          v.push_back('6');
        } else if (ans[j] == 'o') {
          if (ans[j - 1] == 'm' || ans[j - 1] == 'n' || ans[j - 1] == 'o') {
            v.push_back(' ');
          }
          v.push_back('6');
          v.push_back('6');
          v.push_back('6');
        } else if (ans[j] == 'p') {
          if (ans[j - 1] == 'p' || ans[j - 1] == 'q' || ans[j - 1] == 'r' ||
              ans[j - 1] == 's') {
            v.push_back(' ');
          }
          v.push_back('7');
        } else if (ans[j] == 'q') {
          if (ans[j - 1] == 'p' || ans[j - 1] == 'q' || ans[j - 1] == 'r' ||
              ans[j - 1] == 's') {
            v.push_back(' ');
          }
          v.push_back('7');
          v.push_back('7');
        } else if (ans[j] == 'r') {
          if (ans[j - 1] == 'p' || ans[j - 1] == 'q' || ans[j - 1] == 'r' ||
              ans[j - 1] == 's') {
            v.push_back(' ');
          }
          v.push_back('7');
          v.push_back('7');
          v.push_back('7');
        } else if (ans[j] == 's') {
          if (ans[j - 1] == 'p' || ans[j - 1] == 'q' || ans[j - 1] == 'r' ||
              ans[j - 1] == 's') {
            v.push_back(' ');
          }
          v.push_back('7');
          v.push_back('7');
          v.push_back('7');
          v.push_back('7');
        } else if (ans[j] == 't') {
          if (ans[j - 1] == 't' || ans[j - 1] == 'u' || ans[j - 1] == 'v') {
            v.push_back(' ');
          }
          v.push_back('8');
        } else if (ans[j] == 'u') {
          if (ans[j - 1] == 't' || ans[j - 1] == 'u' || ans[j - 1] == 'v') {
            v.push_back(' ');
          }
          v.push_back('8');
          v.push_back('8');
        } else if (ans[j] == 'v') {
          if (ans[j - 1] == 't' || ans[j - 1] == 'u' || ans[j - 1] == 'v') {
            v.push_back(' ');
          }
          v.push_back('8');
          v.push_back('8');
          v.push_back('8');
        } else if (ans[j] == 'w') {
          if (ans[j - 1] == 'w' || ans[j - 1] == 'x' || ans[j - 1] == 'y' ||
              ans[j - 1] == 'z') {
            v.push_back(' ');
          }
          v.push_back('9');
        } else if (ans[j] == 'x') {
          if (ans[j - 1] == 'w' || ans[j - 1] == 'x' || ans[j - 1] == 'y' ||
              ans[j - 1] == 'z') {
            v.push_back(' ');
          }
          v.push_back('9');
          v.push_back('9');
        } else if (ans[j] == 'y') {
          if (ans[j - 1] == 'w' || ans[j - 1] == 'x' || ans[j - 1] == 'y' ||
              ans[j - 1] == 'z') {
            v.push_back(' ');
          }
          v.push_back('9');
          v.push_back('9');
          v.push_back('9');
        } else if (ans[j] == 'z') {
          if (ans[j - 1] == 'w' || ans[j - 1] == 'x' || ans[j - 1] == 'y' ||
              ans[j - 1] == 'z') {
            v.push_back(' ');
          }
          v.push_back('9');
          v.push_back('9');
          v.push_back('9');
          v.push_back('9');
        } else if (ans[j] == ' ') {
          if (ans[j - 1] == ' ') {
            v.push_back(' ');
          }
          v.push_back('0');
        }
      }
    }

    cout << "Case #" << i + 1 << ": ";
    for (i64 j = 0; j < v.size(); j++) {
      cout << v[j];
    }
    cout << endl;
    v.clear();
  }

  return 0;
}