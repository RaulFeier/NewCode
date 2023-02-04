#include <bits/stdc++.h>

using namespace std;

struct pc {
  int nr_pc;
  double frecventa;
  int ram;
  int memory;
  char tip[10];
};

int main() {
  pc v[100];
  ifstream cin("retea.txt");
  int n;
  cin >> n;

  int y, z;
  double x;
  cin >> x >> y >> z;

  for (int i = 0; i < n; i++) {
    cin >> v[i].nr_pc >> v[i].frecventa >> v[i].ram >> v[i].memory;
    cin.getline(v[i].tip, 10);
  }

  for (int i = 0; i < n; i++) {
    if (v[i].frecventa >= x and v[i].ram >= y and v[i].memory >= z) {
      cout << "Calculatorul cu nr " << v[i].nr_pc << "fi conectat la retea"
           << endl;
    }
  }

  double max_frecventa = 0.0;
  int max_ram = 0;
  int max_memory = 0;
  int procesor = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].frecventa > max_frecventa) {
      max_frecventa = v[i].frecventa;
    }
    if (v[i].ram > max_ram) {
      max_ram = v[i].ram;
    }
    if (v[i].memory > max_memory) {
      max_memory = v[i].memory;
    }
    int a = v[i].tip[strlen(v[i].tip)] -
            '0'; // ultimu element indica nr procesorului
    if (a > procesor) {
      procesor = a;
    }
  }

  cout << max_frecventa << " " << max_ram << " " << max_memory << " "
       << procesor << endl;

  return 0;
}