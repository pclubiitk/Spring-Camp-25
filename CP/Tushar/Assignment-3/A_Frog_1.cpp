#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
void solve() {
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll> dp(200001,0);
    dp[2]=abs(v[1]-v[0]);
    for(int i=3;i<=n;i++){
        dp[i]=min(dp[i-1]+abs(v[i-1]-v[i-2]),dp[i-2]+abs(v[i-1]-v[i-3]));
    }
    cout<<dp[n]<<endl;;
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}