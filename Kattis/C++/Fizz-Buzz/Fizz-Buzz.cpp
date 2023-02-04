#include <bits/stdc++.h>

using namespace std;
typedef int64_t i64;
using d6 = long double;

int main()
{
    i64 x,y,n;

    cin >> x >> y >> n;
    
    for(i64 i = 1;i <= n; i++)
    {
        if(i % x == 0 && i % y == 0)
        {
            cout << "FizzBuzz" << endl;
        }
        else if(i % x ==0)
        {
            cout << "Fizz" << endl;
        }
        else if(i % y == 0)
        {
            cout << "Buzz" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }

}