

#include <iostream>

using namespace ::std;

typedef int64_t ll;

int main()
{
    ll n, pow = 1, res = 1;
    cin >> n;
    
    for (int i = 2; i < 129; i++)
    {
        pow = 1;
        for (int j = 0; j < 9; j++)
        {
            pow *= i;
        }
        if (pow > n)
        {
            break;
        }
        else if (n % pow == 0)
        {
            res = i;
        }
    }
    
    cout << res << endl;
    return 0;
}