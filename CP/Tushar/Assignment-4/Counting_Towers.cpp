#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll mod=1e9+7;
vector<ll> ans(1e6+3,0);
void fun(){
    ans[1]=2;
    ans[2]=8;
    ll pow=8;
    for(ll i=3;i<=1e6;i++){
        ans[i]=(4*ans[i-1]-ans[i-2]*4-pow)%mod;
        pow=(pow*2)%mod;
    }
}
void solve() {
    ll n;
    cin>>n;
    cout<<ans[n]<<"\n";
}
int main(){
    ll t;
    t=1;
    cin>>t;
    fun();
    while(t--){
        solve();
    }
}