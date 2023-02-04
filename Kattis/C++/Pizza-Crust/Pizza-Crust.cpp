#include <iostream>
#include <cmath>
using namespace::std;
int main()
{
    double C,R;
    cin >> R >> C;
    
    cout.precision(7);
    cout << fixed;
    cout << (((R - C) * (R - C)) / (R * R)) * 100 << endl;

    return 0;
}