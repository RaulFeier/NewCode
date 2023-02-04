#include <bits/stdc++.h>

using namespace::std;
int main()
{
    long long x, s = 0;
    cin >> x;
    long long i = 2;
    
    while(i * i <= x)
    {
        if(x % i == 0)
        {

            s+=1;
            x /=i;
    
        }   
        else
        {
            i++;
        }

    }

    cout << s + 1 << endl;

    return 0;
}
