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
    ll i=1;
    ll sum=0;
    while(i<=n){
        ll q=n/i;
        ll z=n/q+1;
        ll oo=  ((long long)(z - i) * (i + (z - 1)) / 2) % mod;
        sum= (sum+(q*oo)%mod)%mod;
        i=z;
    }
    cout<<sum<<endl;
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}