#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
void solve() {
    ll n;
    cin>>n;
    vector<pair<ll,ll>> v;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({y,x});
    }
    sort(v.begin(),v.end());
    // for(auto k:v){
    //     cout<<k.first<<" "<<k.second<<"\n";
    // }
    ll start=0;
    ll ans=0;   
    for(int i=0;i<n;i++){
        if(v[i].second>=start){
            start=v[i].first;
            ans++;
        }
    }
    cout<<ans<<"\n";
 
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}