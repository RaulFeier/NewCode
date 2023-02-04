#include <iostream>

using namespace std;
typedef int64_t i64;

int main()
{
    i64 t;
    cin >> t;
    cout << endl;

    for (i64 i = 0; i < t; i++)
    {
        i64 n, m;
        cin >> n >> m;
        i64 v[n];
        i64 a[m];

        long double q = 0.0, p = 0.0;
        
        for (i64 i = 0; i < n; i++)
        {
            cin >> v[i];
            q += v[i];
        }
        
        q /= n;
        
        for (i64 i = 0; i < m; i++)
        {
            cin >> a[i];
            p += a[i];
        }
        
        p /= m;
        i64 res = 0;
        
        for (i64 i = 0; i < n; i++)
        {
            if (q > v[i] && v[i] > p)
            {
                res++;
            }
        }
        cout << res << "\n";
    }

    //works for both versions 
}