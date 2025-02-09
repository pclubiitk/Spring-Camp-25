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
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    if(n & 1){
        ll sum=0;
        ll idx=n/2;
        for(int i=0;i<n;i++){
            sum+=abs(v[i]-v[idx]);
        }
        cout<<sum<<"\n";
        return;
    }
    else{
        ll ans=1000000000000000000;
        ll sum=0;
        ll idx=n/2;
        for(int i=0;i<n;i++){
            sum+=abs(v[i]-v[idx]);
        }
        ans=min(ans,sum);
        sum=0;
        idx=n/2-1;
        for(int i=0;i<n;i++){
            sum+=abs(v[i]-v[idx]);
        }
        ans=min(ans,sum);
        cout<<ans<<"\n";
    }
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}