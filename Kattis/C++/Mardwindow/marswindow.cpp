#include <iostream>
using namespace ::std;

int main()
{
    int a;

    bool ver = false;
    
    cin >> a;
    a *= 12;
    
    for (int i = 1; i < 13; i++, a--)
    {
        if (a % 26 == 2)
        {
            ver = true;
        }
    }
    if (ver)
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
    
    return 0;
}