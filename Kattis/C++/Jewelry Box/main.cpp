#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main()
{
	i64 t;
	cin >> t;
	
	while (t-- > 0)
	{
		i64 x, y;
		cin >> x >> y;
		
		double h1, h2;
		h1 = (4 * (x + y) - sqrt(16 * (x + y) * (x + y) - 48 * x * y)) / 24;
		h2 = (4 * (x + y) + sqrt(16 * (x + y) * (x + y) - 48 * x * y)) / 24;
		double v1, v2;
		
		v1 = (x - 2 * h1) * (y - 2 * h1) * h1;
		v2 = (x - 2 * h2) * (y - 2 * h2) * h2;
		cout << fixed << setprecision(7);
		cout << max(v1,v2) << endl;
	}
	
	return 0;

}
