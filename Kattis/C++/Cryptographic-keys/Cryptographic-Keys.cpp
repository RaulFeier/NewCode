#include <iostream>
#include <cmath>

using namespace std;
typedef int64_t i64;

int main()
{
    i64 n;
    cin >> n;
    i64 mx = 0;
    i64 a = n;
    i64 b = 0;

    while(n % 2 == 0)
    {
        b++;
        n = n / 2;
    }
    if (mx < b)
    {
        mx = b;
        a = 2;
    }
    for(i64 i = 3;i * i <= n;i += 2)
    {
        b = 0;
        while(n % i == 0)
        {
            b++;
            n = n / i;
        }
        if(mx < b)
        {
            mx = b;
            a = i;
        }
    }
    
    cout << a << endl;

}
