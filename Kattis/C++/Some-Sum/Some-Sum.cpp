#include <iostream>
using namespace::std;

int main()
{
    int s,d;
    cin >> s;
    d = s % 4;
    
    if(d == 0)
    {
        cout << "even" << endl;
    }
    else if(d == 2)
    {
        cout << "Odd" << endl;
    }
    else
    {
        cout << "Either" << endl;
    }

}
