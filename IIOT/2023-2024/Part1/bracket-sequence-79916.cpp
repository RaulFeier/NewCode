// @check-accepted: examples NVerysmall NASumSmall no-limits
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int dp[501][25001];
int par[501][25001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> A(n+1);
    for(int i=1;i<=n;++i) {
        cin>>A[i];
    }
 
    int sum=accumulate(A.begin(), A.end(), 0);
    if(sum&1) {
        cout<<"-1\n";
        return 0;
    }

    dp[0][0]=1;
    int pref=0;
    for(int i=0;i<n;++i) {
        pref+=A[i];
        for(int j=0;j<=min(25000, pref);++j) {
            if(dp[i][j]) {
                if(j+A[i+1]<=25000) {
                    dp[i+1][j+A[i+1]]=1;
                    par[i+1][j+A[i+1]]=1;
                }
                if(j-A[i+1]>=0) {
                    dp[i+1][j-A[i+1]]=1;
                    par[i+1][j-A[i+1]]=2;
                }
            }
        }
    }

    if(!dp[n][0]) {
        cout<<"-1\n";
        return 0;
    }
    
    string ans;
    pair<int,int> st={n, 0};
    while(st.first>0) {
        char ch=par[st.first][st.second]==1?'(':')';
        for(int j=0;j<A[st.first];++j) {
            ans.push_back(ch);
        }
        
        if(ch=='(') st.second-=A[st.first];
        else st.second+=A[st.first];
        
        st.first--;
    }
    
    reverse(ans.begin(), ans.end());
    cout<<ans<<"\n";
    return 0;
}
