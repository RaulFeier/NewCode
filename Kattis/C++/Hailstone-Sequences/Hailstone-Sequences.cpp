#include <iostream>
#include <cmath>
using namespace::std;
int main()
{
    long long n;
    cin >> n;
    long long h=1;
    
    while(n!=1)
    {
        h += 1;
        if(n%2==0)
        {
            n/=2;
        }
        else
        {
            n = 3 * n + 1;
        }

    }
    cout << h << endl;
    return 0;
}
