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
    sort(v.begin(),v.end());
    ll left=0,right=1e9;
    ll ans=right;
    ll idx=v[0];
    ll gg=1;
    // for(auto j:v){
    //     cout<<j<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<n;i++){
    //     if(v[i]-idx>=3){
    //         idx=v[i];
    //         gg++;
    //     }
    // }
    // cout<<gg<<"ll\n";
    while(left<=right){
        ll mid=(left+right)/2;
        // cout<<left<<" "<<right<<" ll\n";
        ll idx=v[0];
        ll gg=1;
        for(int i=1;i<n;i++){
            if(v[i]-idx>=mid){
                idx=v[i];
                gg++;
            }
        }
        if(gg>=k){
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
    cin>>t;
    while(t--){
        solve();
    }
}