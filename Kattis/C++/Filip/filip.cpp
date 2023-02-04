#include <iostream>

using namespace ::std;

typedef int64_t i64;

int main()
{
    i64 a, b, c = 0, d = 0;

    cin >> a >> b;

    while (a)
    {
        c *= 10;
        c += a % 10;
        a /= 10;
    }

    while (b)
    {
        d *= 10;
        d += b % 10;
        b /= 10;
    }
    
    if (c > d)
    {
        cout << c << endl;
    }
    else
    {
        cout << d << endl;
    }

    return 0;
}