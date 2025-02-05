#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
void solve() {
    string f;
    cin>>f;
    ll b,s,c;
    cin>>b>>s>>c;
    ll pb,ps,pc;
    cin>>pb>>ps>>pc;
    ll money;
    cin>>money;
    ll nb=0,ns=0,nc=0;
    for(int i=0;i<f.length();i++){
        if(f[i]=='B'){nb++;}
        else if(f[i]=='C'){nc++;}
        else{ns++;}
    }
    ll left=0,right=1e13;
    ll ans=right;
    while(left<=right){
        ll mid=(left+right)/2;
        ll x=max(ll(0),(mid*nb-b))*pb;
        ll y=max(ll(0),(mid*ns-s))*ps;
        ll z=max(ll(0),(mid*nc-c))*pc;
        ll cost=x+y+z;
        // cout<<left<<" "<<cost<<" "<<right<<endl;
        if(cost<=money){
            ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout<<ans<<endl;
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}