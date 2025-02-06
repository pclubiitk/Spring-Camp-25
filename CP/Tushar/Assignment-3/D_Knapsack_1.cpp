#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
void solve() {
    ll n,w;
    cin>>n>>w;
    vector<pair<ll,ll>> v(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[i]={x,y};
    }
    vector<vector<ll>>ans(n+1,vector<ll>(w+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++){
            ans[i][j]=ans[i-1][j];
            // cout<<" kk\n";
            if(v[i-1].first<=j){
                ans[i][j]=max(ans[i-1][j],v[i-1].second+ans[i-1][j-v[i-1].first]);
            }
            // cout<<ans[i][j]<<" ";
        }
        // cout<<endl;
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=w;j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<ans[n][w]<<endl;
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}