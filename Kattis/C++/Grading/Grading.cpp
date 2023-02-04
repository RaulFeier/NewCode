#include <iostream>
using namespace::std;

int main(){

    int a, b, c, d, e, x;
    cin >> a >> b >> c >> d >> e;
    cin >> x;

    if ( x >= a )
    {
        cout << "A" << endl;
    }
    else if ( x >= b )
    {
        cout << "B" << endl;
    }
    else if ( x >= c )
    {
        cout << "C" << endl;
    }
    else if ( x >= d )
    {
        cout << "D" << endl;
    }
    else if ( x >= e )
    {
        cout << "E" << endl;
    }
    else
    {
        cout << "F" << endl;
    }
}