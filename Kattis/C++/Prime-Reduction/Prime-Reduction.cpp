#include <cmath>
#include <iostream>

using namespace ::std;

typedef int64_t ll;

bool checker(ll n)
{
    ll steps = 0;
    for (int i = 2; i * i <= n;)
    {
        if (n % i == 0)
        {
            n /= i;
            steps++;
        }
        else
        {
            i++;
        }
    }
    if (steps == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    ll n;
    cin >> n;
    while (n != 4)
    {
        ll exec = 1;
        while (checker(n))
        {
            exec++;
            ll sum = 0;
            for (int i = 2; i * i <= n; i++)
            {
                while (n % i == 0)
                {
                    sum += i;
                    n /= i;
                }
            }
            if (n != 1)
            {
                sum += n;
            }

            n = sum;
        }
        cout << n << " " << exec << endl;
        cin >> n;
    }
    return 0;
}