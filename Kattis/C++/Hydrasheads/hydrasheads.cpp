#include <iostream>
using namespace ::std;

int main()
{
    int h = 1, t = 1, c = 0;

    while (cin >> h >> t && (h != 0 && t != 0))
    {
        c = 0;
        while (t > 1)
        {
            t -= 2;
            c++;
            h++;
        }
        if (t == 1)
        {
            t--;
            c += 2;
            h++;
        }
        while (h > 1)
        {
            h -= 2;
            c++;
        }
        if (h == 1)
        {
            c += 4;
        }
        if (c > 0)
        {
            cout << c << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    
    return 0;
}