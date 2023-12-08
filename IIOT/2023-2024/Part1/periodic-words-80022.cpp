#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define sz(x) (int)(x).size()

struct rolling_hash { 
	vector<ll> lst;
	vector<ll> hatv;
	int n;
	
	ll p;
	ll mod; 

	rolling_hash(string& t, ll p_, ll mod_) {
		lst.resize(sz(t));
		hatv.resize(sz(t));
		n=sz(t);
		
		p=p_;
		mod=mod_;
		
		ll curr=p;
		
		lst[0]=t[0]%mod;
		hatv[0]=1;
		for(int i=1;i<sz(t);++i) {
			lst[i]=(lst[i-1]+curr*t[i])%mod;
			hatv[i]=curr;
			curr=(curr*p)%mod;
		}
	}
	
	ll base_hash(ll l, ll r) {
		ll hsh=(lst[r]-(l>0?lst[l-1]:0)+mod);
		return (hsh*hatv[n-l-1])%mod; //így mindig sz(t)-1 hatványon van
	}
	
	bool probably_equal(ll l1, ll r1, ll l2, ll r2) {				
		if(r1-l1!=r2-l2) return false;

		if(l1>l2) {
			swap(l1, l2);
			swap(r1, r2);
		}
				
		ll egyik=(lst[r2]-(l2>0?lst[l2-1]:0)+mod), masik=(lst[r1]-(l1>0?lst[l1-1]:0)+mod);
		return (egyik-(masik*hatv[l2-l1]))%mod==0; //WATCH OUT FOR THIS KIND OF ERROR!!
	}
};

vector<int> divs[100001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<100001;++i) {
        for(int j=2*i;j<100001;j+=i) {
            divs[j].push_back(i);
        }
    }
    for(int i=1;i<100001;++i) {
        reverse(divs[i].begin(), divs[i].end());
    }

    int n,q;
    cin>>n;
    string s;
    cin>>s;

    rolling_hash hsh1(s, 31, 1e9+7), hsh2(s, 91, 998244353);

    cin>>q;
    while(q--) {
        int l,r;
        cin>>l>>r;
        bool ans=false;
        for(int i:divs[r-l+1]) {
            bool ok=hsh1.probably_equal(l,r-i,l+i,r) && hsh2.probably_equal(l,r-i,l+i,r);

            ans|=ok;
            if(ans) break ;
        }
        cout<<(ans?"YES":"NO")<<"\n";
    }
    return 0;
}
