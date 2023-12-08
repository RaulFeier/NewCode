#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int dp[6][6][102][102];
int fw[2][6][6][102][102];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	dp[0][0][0][0] = 1;
	
	for(int sets = 0; sets <= 4; sets++)
	{
		for(int wins_a = 0; wins_a <= 2; wins_a++)
		{
			if(sets - wins_a >= 3)
				continue;
			for(int score_a = 0; score_a <= 100; score_a++)
			{
				for(int score_b = 0; score_b <= 100; score_b++)
				{
					if(dp[sets][wins_a][score_a][score_b] == 0)
						continue;
					for(int b = 0; b <= 10; b++)
					{
						if(score_a + 11 <= 100 && score_b + b <= 100)
						{
							dp[sets+1][wins_a + 1][score_a + 11][score_b + b] = 1;
							fw[0][sets+1][wins_a + 1][score_a + 11][score_b + b] = score_a;
							fw[1][sets+1][wins_a + 1][score_a + 11][score_b + b] = score_b;
						}
						if(score_b + 11 <= 100 && score_a + b <= 100)
						{
							dp[sets+1][wins_a][score_a + b][score_b + 11] = 1;
							fw[0][sets+1][wins_a][score_a + b][score_b + 11] = score_a;
							fw[1][sets+1][wins_a][score_a + b][score_b + 11] = score_b;
						}
					}
				}
			}
		}
	}
	
	for(; t; t--)
	{
		int score_a, score_b;
		cin >> score_a >> score_b;
		int ok = 0;
		for(int sets = 3; ok == 0 && sets <= 5; sets++)
		{
			if(dp[sets][3][score_a][score_b])
			{
				deque<pair<int, int> > ans;
				int sett = sets;
				int A = 3;
				while(score_a || score_b)
				{
					int px = fw[0][sett][A][score_a][score_b];
					int py = fw[1][sett][A][score_a][score_b];
					ans.push_front({score_a - px, score_b - py});
					if(score_a - px > score_b - py)
						A--;
					score_a = px;
					score_b = py;
					sett--;
				}
				for(auto x : ans)
					cout << x.first << " " << x.second << '\n';
				ok = 1;
				break;
			}
		}
		if(ok == 0)
			cout << "-1 -1\n";
	}
	return 0;
}

