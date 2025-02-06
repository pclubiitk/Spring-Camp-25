#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll> dp(200001,1e17);
    dp[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=max(ll(1),i-1-k+1);j--){
            dp[i]=min(dp[i],dp[j]+abs(v[i-1]-v[j-1]));
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<" ll\n";
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