#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
#define F first
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

bool isPos(ll B, ll S, ll C,ll nb,ll ns,ll nc, int pb, int ps, int pc, ll r, ll count){
    r=r-max(count*B-nb,0ll)*pb;
    r=r-max(count*C-nc,0ll)*pc;
    r=r-max(count*S-ns,0ll)*ps;
    return r>=0;
}

void solve(){
    string s;
    cin>>s;
    ll B=count(s.begin(),s.end(),'B');
    ll S=count(s.begin(),s.end(),'S');
    ll C=count(s.begin(),s.end(),'C');
    ll nb,ns,nc;
    cin>>nb>>ns>>nc;
    int pb,ps,pc;
    cin>>pb>>ps>>pc;
    ll r;
    cin>>r;
    ll l=0;ll R=1e13;
    ll ans;
    while(l<=R){
        ll mid=(l+R)/2;
        bool val=isPos(B,S,C,nb,ns,nc,pb,ps,pc,r,mid);
        if(val){
            ans=mid;
            l=mid+1;
        } else R=mid-1;
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}