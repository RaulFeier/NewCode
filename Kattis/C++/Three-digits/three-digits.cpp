#include <iostream>
#include <string>
using namespace ::std;

int main()
{
    long long int n, r = 1, fact = 1;

    int twos = 0, fives = 0;
    
    string res;
    
    cin >> n;
    
    for (long long int i = 2; i <= n; i++)
    {
        r = i;
        while (r % 5 == 0)
        {
            r = r / 5;
            fives++;
        }
        while (r % 2 == 0)
        {
            r = r / 2;
            twos++;
        }
        fact = (fact * r) % 1000;
    }
    
    int tfIndex = (twos - fives);
    
    while (tfIndex--)
    {
        fact = (fact * 2) % 1000;
    }
    if (n == 0)
    {
        res = "1";
    }
    else if (fact < 100 && n < 7)
    {
        res = to_string(fact);
    }
    else if (fact < 10 && n > 6)
    {
        res = "00" + to_string(fact);
    }
    else if (fact < 100 && n > 6)
    {
        res = "0" + to_string(fact);
    }
    else
    {
        res = to_string(fact);
    }
    
    cout << res << endl;
    
    return 0;
}