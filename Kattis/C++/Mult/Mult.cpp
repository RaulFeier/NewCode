#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main(){
    i64 n, b, a, j = -1 , k = 0;

    vector<i64> v(1001,0);

    cin >> n;
    for(i64 i = 0;i < n;i++)
    {
        j++;
        cin >> a;

        if(j == 0)
        {
            b = a;
        }
        if(a % b == 0 && j != 0)
        {
            v[k] = a;
            j = -1;
            k += 1;
        }
    }

    for(i64 z = 0;z < n;z++)
    {
        if(v[z] != 0)
        {
            cout << v[z] << "\n";
        }
    }

}