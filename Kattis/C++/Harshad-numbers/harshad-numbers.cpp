#include <iostream>

using namespace ::std;

typedef int64_t i64;

bool checker(i64 n)
{
    i64 x = 0, a = n;

    while (a)
    {
        x += a % 10;
        a /= 10;
    }

    if (n % x == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    i64 n;

    cin >> n;
    
    while (!checker(n))
    {
        n++;
    }

    cout << n << endl;
    
    return 0;
}