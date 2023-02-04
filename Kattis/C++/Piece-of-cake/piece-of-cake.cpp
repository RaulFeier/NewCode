#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
    int n, h, v;
    
    cin >> n >> h >> v;
    
    if (h * 2 >= n && v * 2 >= n) 
    {
        cout << h * v * 4;
    }
    if (h * 2 >= n && v * 2 < n) 
    {
        cout << h * (n - v) * 4;
    }
    if (h * 2 < n && v * 2 < n) 
    {
        cout << (n - h) * (n - v) * 4;
    }
    if (h * 2 < n && v * 2 >= n) 
    {
        cout << (n - h) * v * 4;
    }

    return 0;
}