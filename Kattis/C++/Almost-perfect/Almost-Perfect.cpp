#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

typedef int64_t i64;
using d6=long double;

int main()
{
    long long n;
    
    while(cin >> n)
    {
        long long tot = 1;
        
        for(i64 i = 2;i * i <= n;i++)
        {
            if(n % i == 0)
            {
                tot += i;
                
                if (i != n / i) 
                {
                    tot += n / i;
                }
            }
        }
        if (tot == n) 
        {
            cout << n << " " << "perfect" << endl;
        } 
        else if (abs(tot - n) <= 2) 
        {
            cout << n << " " << "almost perfect" << endl;
        } 
        else 
        {
            cout << n << " "  << "not perfect" << endl;        
        }  
    }
}