#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using d6 = long double;

int main()
{
        map<string, i64> votes;

        string name;
        
        getline(cin,name);
        i64 tot =0;
        
        while(name != "***")
        {                
            votes[name]+=1;
            tot+=1;
            getline(cin,name);
        }
        
        i64 maxx =0;
        i64 maxc =0;
        string winner = "";
        
        for(auto kv : votes)
        {
            if(kv.second > maxx)
            {
                   winner = kv.first;
                   maxc = 1;
                   maxx = kv.second;
            }
            else
            {
                if(kv.second == maxx)
                {
                    maxc++;
                }
            }
        }
        
        if(maxc == 1)
        {
            cout << winner;
        }else
        {
            cout <<"Runoff!\n";
        }
        
        return 0;

}