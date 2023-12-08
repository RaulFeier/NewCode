// @check-accepted: examples NVerysmall NASumSmall no-limits
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<functional>
#include<map>
#include<utility>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;++i) {
        cin>>A[i];
    }
    
    vector<int> res(n);
    vector<array<int, 50001>> vis(n+1);
    function<void(int,int)> gen=[&](int ind, int sum) {
        if(vis[ind][sum]) return ;
        vis[ind][sum]=1;

        if(ind==n) {
            if(sum==0) {
                for(int j=0;j<n;++j) {
                    for(int k=0;k<A[j];++k) {
                        cout<<(res[j]?'(':')');
                    }
                }
                cout<<"\n";

                exit(0);
            }
            return ;
        }

        res[ind]=1;
        gen(ind+1, sum+A[ind]);
        res[ind]=0;
        if(sum-A[ind]>=0) gen(ind+1, sum-A[ind]);
    };

    gen(0,0);
    cout<<"-1\n";
    
    return 0;
}
