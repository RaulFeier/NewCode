#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
    i64 T;
    cin >> T;

    for(i64 x = 0; x < T; x++)
    {
        i64 P, K, F;
        i64 i=0;
        cin >> P >> K >> F;
        
        while(P <= F)
        {
            P = P * K;
            i++;
        }
        cout << i << endl;

    }
    return 0;
}
