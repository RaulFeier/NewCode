/*    ___                       ___           ___
     /\__\          ___        /\  \         /\__\
    /::|  |        /\  \      /::\  \       /:/  /
   /:|:|  |        \:\  \    /:/\ \  \     /:/  /
  /:/|:|__|__      /::\__\  _\:\~\ \  \   /:/  /  ___
 /:/ |::::\__\  __/:/\/__/ /\ \:\ \ \__\ /:/__/  /\__\
 \/__/~~/:/  / /\/:/  /    \:\ \:\ \/__/ \:\  \ /:/  /
       /:/  /  \::/__/      \:\ \:\__\    \:\  /:/  /
      /:/  /    \:\__\       \:\/:/  /     \:\/:/  /
     /:/  /      \/__/        \::/  /       \::/  /
     \/__/                     \/__/         \/__/
*/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

i64 here = 0;

struct artist {
  string name;
  string streams;
  string feats;
  short tracks;
  short one_b;
  short mili;
  string last;
};

i64 conv(string &x) {
  i64 e = 0;
  for (short i = 0; i < x.size(); i++) {
    if (x[i] != ',') {
      short b = x[i] - '0';
      e += b;
      e *= 10;
    }
  }

  return e;
}

string read_name(string &ans) {
  string name = "";
  i64 vcnt = 0;
  for (i64 i = 0; i < ans.size(); i++) {
    if (ans[i] == ',' and (ans[i - 1] <= '9' and ans[i - 1] >= '0')) {
      here = i;
      break;
    }
  }

  here++;

  for (i64 i = here; i < ans.size(); i++) {
    if (ans[i] == '"' and (ans[i + 1] <= '9' and ans[i + 1] >= '1')) {
      here = i;
      break;
    } else {
      name += ans[i];
    }
  }

  name.pop_back();

  string name1 = "";
  for (auto &x : name) {
    if (x != '"') {
      name1 += x;
    }
  }

  return name1;
}

string read_streams(string &ans) {
  string streams = "";
  here++;

  for (i64 i = here; i < ans.size(); i++) {
    if (ans[i] == '"') {
      here = i;
      break;
    } else {
      streams += ans[i];
    }
  }

  return streams;
}

string have_numbers(string &ans) {
  string feats = "";
  here += 2;

  for (i64 i = here; i < ans.size(); i++) {
    if (ans[i] == '"') {
      here = i;
      break;
    } else {
      feats += ans[i];
    }
  }

  return feats;
}

string read_feats(string &ans) {
  string feats = "";
  here++;

  if (ans[here + 1] == '"') {
    feats = have_numbers(ans);
  } else {
    feats += '0';
    here++;
  }
  return feats;
}

short read_tracks(string &ans) {
  here += 2;
  short nr = 0;

  if (ans[here] == '"') {
    here++;
    for (i64 i = here; i < ans.size(); i++) {
      if (ans[i] == '"') {
        here = i + 1;
        break;
      }
      if (ans[i] != ',') {
        nr = nr * 10 + (ans[i] - '0');
      }
    }
  } else {
    for (i64 i = here; i < ans.size(); i++) {
      if (ans[i] == ',') {
        here = i;
        break;
      } else {
        nr = nr * 10 + (ans[i] - '0');
      }
    }
  }

  return nr;
}

short read_one_b(string &ans) {
  here++;
  short nr = 0;

  for (i64 i = here; i < ans.size(); i++) {
    if (ans[i] == ',') {
      here = i;
      break;
    } else {
      nr = nr * 10 + (ans[i] - '0');
    }
  }

  return nr;
}

short read_mili(string &ans) {
  here++;
  short nr = 0;

  for (i64 i = here; i < ans.size(); i++) {
    if (ans[i] == ',') {
      here = i;
      break;
    } else {
      nr = nr * 10 + (ans[i] - '0');
    }
  }

  return nr;
}

string read_last(string &ans) {
  string last = "";
  here++;
  for (i64 i = here; i < ans.size(); i++) {
    last += ans[i];
  }

  here = 0;
  return last;
}

void read_csv(string &ans, vector<artist> &main) {
  ifstream fin("spotify_artist_data.csv");
  ofstream oin("spotify-artist-out.csv");

  i64 index = 0;
  i64 size = 0;

  while (getline(fin, ans)) {
    main.resize(++size);
    main[index].name = read_name(ans);
    main[index].streams = read_streams(ans);
    main[index].feats = read_feats(ans);
    main[index].tracks = read_tracks(ans);
    main[index].one_b = read_one_b(ans);
    main[index].mili = read_mili(ans);
    main[index].last = read_last(ans);

    index++;
  }
}

void print_welcome() {
  cout << endl;
  cout << " /$$      /$$           /$$" << endl;
  cout << "| $$  /$ | $$          | $$" << endl;
  cout << "| $$ /$$$| $$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   "
          "/$$$$$$"
       << endl;
  cout << "| $$/$$ $$ $$ /$$__  $$| $$ /$$_____/ /$$__  $$| $$_  $$_  $$ /$$__ "
          " $$"
       << endl;
  cout << "| $$$$_  $$$$| $$$$$$$$| $$| $$      | $$  " << char(92)
       << " $$| $$ " << char(92) << " $$ " << char(92) << "$$| $$$$$$$$"
       << endl;
  cout << "| $$$/ " << char(92)
       << "  $$$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/"
       << endl;
  cout << "| $$/   " << char(92)
       << " $$|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  "
          "$$$$$$$"
       << endl;
  cout << "|__/     " << char(92) << "__/ " << char(92) << "_______/|__/ "
       << char(92) << "_______/ " << char(92) << "______/ |__/ |__/ |__/ "
       << char(92) << "_______/" << endl;

  cout << endl;
  cout << endl;
}

bool play() {
  cout << "Vreti sa folositi baza mea de date pentru 1000 de artisit? ";
  cout << "[Yes/No] ";
  while (true) {
    string answer;
    cin >> answer;
    if (answer == "Yes") {
      cout << "Are u sure? ";
      cout << "[Yes/No] ";
      cin >> answer;
      if (answer == "Yes") {
        return true;
      } else if (answer == "No") {
        return false;
      } else {
        while (true) {
          cout << "Enter again ";
          cout << "[Yes/No] ";
          cin >> answer;
          if (answer == "Yes") {
            return true;
          } else if (answer == "No") {
            return false;
          } else {
            "Enter again ";
          }
        }
      }
    } else if (answer == "No") {
      return false;
    } else {
      cout << "Enter again ";
    }
  }
}

void read_rules() {
  ifstream f{"rules.csv"};
  while (!f.eof()) {
    string s;
    getline(f, s);
    cout << s << endl;
  }
}

void a1(string &artist_name, vector<artist> &main) {
  cout << endl;
  bool exista = false;

  for (int i = 0; i < main.size(); i++) {
    if (main[i].name == artist_name) {
      cout << "Streams: " << main[i].streams << endl;
      cout << "Feats: " << main[i].feats << endl;
      cout << "Tracks: " << main[i].tracks << endl;
      cout << "One Billion Songs: " << main[i].one_b << endl;
      cout << "100 Million Songs: " << main[i].mili << endl;
      exista = true;
    }
  }

  if (!exista) {
    cout << "Artistul cautat nu exista" << endl;
  }
}

void b1(string &artist_name, vector<artist> &main) {
  cout << endl;
  bool exista = false;

  for (int i = 0; i < main.size(); i++) {
    if (main[i].name == artist_name) {
      cout << "Streams: " << main[i].streams << endl;
      exista = true;
    }
  }

  if (!exista) {
    cout << "Artistul cautat nu exista" << endl;
  }
}

void c1(string &artist_name, vector<artist> &main) {
  cout << endl;
  bool exista = false;

  for (int i = 0; i < main.size(); i++) {
    if (main[i].name == artist_name) {
      cout << "Feats: " << main[i].feats << endl;
      exista = true;
    }
  }

  if (!exista) {
    cout << "Artistul cautat nu exista" << endl;
  }
}

void d1(string &artist_name, vector<artist> &main) {
  cout << endl;
  bool exista = false;

  for (int i = 0; i < main.size(); i++) {
    if (main[i].name == artist_name) {
      cout << "Tracks: " << main[i].tracks << endl;
      exista = true;
    }
  }

  if (!exista) {
    cout << "Artistul cautat nu exista" << endl;
  }
}

void e1(string &artist_name, vector<artist> &main) {
  cout << endl;
  bool exista = false;

  for (int i = 0; i < main.size(); i++) {
    if (main[i].name == artist_name) {
      cout << "One Billion Songs: " << main[i].one_b << endl;
      exista = true;
    }
  }

  if (!exista) {
    cout << "Artistul cautat nu exista" << endl;
  }
}

void f11(string &artist_name, vector<artist> &main) {
  cout << endl;
  bool exista = false;

  for (int i = 0; i < main.size(); i++) {
    if (main[i].name == artist_name) {
      cout << "100 Million Songs: " << main[i].mili << endl;
      exista = true;
    }
  }

  if (!exista) {
    cout << "Artistul cautat nu exista" << endl;
  }
}

void f1(vector<artist> &main) {
  string name;
  char litera;

  cout << endl;
  cout << "Name: ";
  cin.get();
  getline(cin, name);
  cout << endl;

  cout << "Alege-ti litera: ";
  cin >> litera;

  if (litera == 'a') {
    a1(name, main);
  } else if (litera == 'b') {
    b1(name, main);
  } else if (litera == 'c') {
    c1(name, main);
  } else if (litera == 'd') {
    d1(name, main);
  } else if (litera == 'e') {
    e1(name, main);
  } else if (litera == 'f') {
    f11(name, main);
  } else {
    cout << "Cifra nu exista" << endl;
  }
}

void f2(vector<artist> &main) {
  cout << main[0].name;
  cout << " cu: " << main[0].streams << endl;
}

void f3(vector<artist> &main) {
  cout << main[0].name;
  cout << " cu: " << main[0].feats << endl;
}

void f4(vector<artist> &main) {
  short index;
  short eep = 0;
  for (short i = 0; i < main.size(); i++) {
    if (eep < main[i].tracks) {
      eep = main[i].tracks;
      index = i;
    }
  }

  cout << main[index].name;
  cout << " cu: " << eep << endl;
}

void f5(vector<artist> &main) {
  short index;
  short eep = 0;
  for (short i = 0; i < main.size(); i++) {
    if (eep < main[i].one_b) {
      eep = main[i].one_b;
      index = i;
    }
  }

  cout << main[index].name;
  cout << " cu: " << eep << endl;
}

void f6(vector<artist> &main) {
  short index;
  short eep = 0;
  for (short i = 0; i < main.size(); i++) {
    if (eep < main[i].mili) {
      eep = main[i].mili;
      index = i;
    }
  }

  cout << main[index].name;
  cout << " cu: " << eep << endl;
}

void f7(vector<artist> &main) {
  short index;
  i64 eep = 1e18;
  for (short i = 0; i < main.size(); i++) {
    if (eep > conv(main[i].streams)) {
      eep = conv(main[i].streams);
      index = i;
    }
  }

  cout << main[index].name;
  cout << " cu: " << eep << endl;
}

struct t {
  i64 feats;
  short index;
};

void f8(vector<artist> &main) {
  short index;
  i64 eep = 1e18;

  for (short i = 0; i < main.size(); i++) {
    if (eep > conv(main[i].feats)) {
      eep = conv(main[i].feats);
      index = i;
    }
  }

  vector<t> v(1);
  v[0].feats = eep;
  v[0].index = index;

  short pos = 1;

  for (short i = index + 1; i < main.size(); i++) {
    if (eep == conv(main[i].feats)) {
      v.resize(pos + 1);
      v[pos].feats = conv(main[i].feats);
      v[pos].index = i;
      pos++;
    }
  }

  cout << "Artisti cu cele mai putine featuri sunt: ";
  for (short i = 0; i < v.size(); i++) {
    cout << main[v[i].index].name << ", ";
  }
  cout << endl;
}

struct s {
  i64 traks;
  short index;
};

void f9(vector<artist> &main) {
  short index;
  i64 eep = 1e18;

  for (short i = 0; i < main.size(); i++) {
    if (eep > main[i].tracks) {
      eep = main[i].tracks;
      index = i;
    }
  }

  vector<s> v(1);
  v[0].traks = eep;
  v[0].index = index;

  short pos = 1;

  for (short i = index + 1; i < main.size(); i++) {
    if (eep == main[i].tracks) {
      v.resize(pos + 1);
      v[pos].traks = main[i].tracks;
      v[pos].index = i;
      pos++;
    }
  }

  cout << "Artisti cu cele mai putine tracks sunt: ";
  for (short i = 0; i < v.size(); i++) {
    cout << main[v[i].index].name << ", ";
  }
  cout << endl;
}

void f10(vector<artist> &main) {}

void f11(vector<artist> &main) {}

int cejucam(vector<artist> &main) {
  short nr;
  cout << endl;
  cout << "Alege-ti numarul: ";
  cin >> nr;

  if (nr == 0) {
    return 0;
  } else if (nr == 1) {
    f1(main);
    return 1;
  } else if (nr == 2) {
    f2(main);
    return 1;
  } else if (nr == 3) {
    f3(main);
    return 1;
  } else if (nr == 4) {
    f4(main);
    return 1;
  } else if (nr == 5) {
    f5(main);
    return 1;
  } else if (nr == 6) {
    f6(main);
    return 1;
  } else if (nr == 7) {
    f7(main);
    return 1;
  } else if (nr == 8) {
    f8(main);
    return 1;
  } else if (nr == 9) {
    f9(main);
    return 1;
  } else if (nr == 10) {
    f10(main);
    return 1;
  } else if (nr == 11) {
    f11(main);
    return 1;
  }

  cout << endl;
  cout << "Reintroduce-ti numarul" << endl;
  return 1;
}

int main() {

  if (!play()) {
    cout << "Multumesc pentru atentie" << endl;
    return 0;
  }
  string ans;
  vector<artist> main;
  read_csv(ans, main);
  print_welcome();
  read_rules();

  while (true) {
    if (cejucam(main) == 0) {
      cout << "Multumesc pentru atentie" << endl;
      return 0;
    }
  }

  return 0;
}