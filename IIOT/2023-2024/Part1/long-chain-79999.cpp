// @check-accepted: examples NVsmall Nsmall Nprettybig nolimits
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100'000;

vector<int> adj[MAXN];

vector<int> vis;

int dfs(int x, int mn_len) {
    vis[x]=1;
    vector<int> lst;
    for(auto i:adj[x]) {
        if(!vis[i])
            lst.push_back(dfs(i, mn_len)+1);
    }

    if(lst.empty()) return 0;
    if(*min_element(lst.begin(), lst.end())<0) return -1e7;

    multiset<int> ms;
    for(int i:lst) ms.insert(i);
    int saved=-1;

    while(ms.size()>2) {
        if(*ms.begin()>=mn_len) {
            ms.erase(ms.begin());
            continue;
        }else {
            auto it=ms.lower_bound(mn_len-*ms.begin());
            if(it==ms.begin()) it=next(it);
            if(it==ms.end()) {
                if(saved==-1) {
                    saved=*ms.begin();
                    ms.erase(ms.begin());
                    continue ;
                }else {
                    return -1e7;
                }
            }
            if(it==ms.end()) return -1e7;
            ms.erase(it);
            ms.erase(ms.begin());
        }
    }

    if(saved!=-1) {
        if(ms.empty()) return saved;
        else if(ms.size()==1) {
            return -1e7;
        }else if(ms.size()==2) {
            if(*ms.begin()+*prev(ms.end())>=mn_len) return saved;
            else return -1e7;
        }
         
    }
    
    if(ms.empty()) return 0;
    else if(ms.size()==1) return *ms.begin();
    else if(ms.size()==2) {
        if(x==1 && *ms.begin()+*prev(ms.end())>=mn_len) return 0; 
        else if(*prev(ms.end())>=mn_len) return *ms.begin();
        else if(*ms.begin()+*prev(ms.end())>=mn_len) return 0;
        else return -1e7;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;++i) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int mn_len=0;
    for(int i=18;i>=0;i--)  {
        int akt=mn_len+(1<<i);
        vis.assign(n+1, 0);
        int res=dfs(1, akt);
        if(res==0 || res>=akt) {
            mn_len=akt;
        }
    }

    cout<<mn_len<<"\n";
}
