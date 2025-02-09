#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll mod=1e9+7;
void solve() {
    ll n;
    cin>>n;
    vector<ll> v(n+1,0);
    v[1]=1;
    for(int i=2;i<n+1;i++){
        if(i<=6){v[i]++;}
        v[i]=(v[i]+v[max(i-1,0)])%mod;
        v[i]=(v[i]+v[max(i-2,0)])%mod;
        v[i]=(v[i]+v[max(i-3,0)])%mod;
        v[i]=(v[i]+v[max(i-4,0)])%mod;
        v[i]=(v[i]+v[max(i-5,0)])%mod;
        v[i]=(v[i]+v[max(i-6,0)])%mod;
    }
    cout<<v[n]%mod<<endl;
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}