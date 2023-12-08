#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	for(; t; t--)
	{
		int a, b;
		cin >> a >> b;
		
		bool ans = 0;
		for(int sets = 3; sets <= 5; sets++)
		{
			vector<int> scora(sets);
			vector<int> scorb(sets);
			int a2 = a;
			int b2 = b;
			for(int i = 0; i < sets - 3; i++)
				scorb[i] = 11, b2 -= 11;
			for(int i = sets - 3; i < sets; i++)
				scora[i] = 11, a2 -= 11;
			
			for(int i = 0; i < sets - 3; i++)
			{
				scora[i] = max(min(10, a2), 0);
				a2 -= scora[i];
			}
			for(int i = sets - 3; i < sets; i++)
			{
				scorb[i] = max(0, min(10, b2));
				b2 -= scorb[i];
			}
			if(a2 == 0 && b2 == 0)
			{
				ans = 1;
				for(int i = 0; i < sets; i++)
					cout << scora[i] << " " << scorb[i] << '\n';
				break;
			}
		}
		if(ans == 0)
			cout << -1 << " " << -1 << '\n';
	}
	return 0;
}

