#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
bool produce(ll time,vector<ll> &v,ll t){
    ll sum=0;
    for(int i=0;i<v.size();i++){
        sum+=time/v[i];
        if(sum>=t){return true;}  
    }
    return false ;
}
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll left=0,right=1e18;
    ll ans=right;
    while(left<=right){
        // cout<<left<<" "<<right<<" kk\n";
        ll mid=(left+right)/2;
        if(produce(mid,v,k)){
            ans=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
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