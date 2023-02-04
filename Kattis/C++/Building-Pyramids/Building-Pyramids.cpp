#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum =0;
    int res = 0;
    int i =1;
    
    while(true)
    {
        sum += i * i;
        if(sum <= n)
        {
            res+=1;
            i+=2;
        }
        else
        {
            break;
        }
    }
    cout<<res<<endl;
}
