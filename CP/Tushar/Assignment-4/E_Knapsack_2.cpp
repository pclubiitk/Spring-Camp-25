
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>
#define pr pair<ll,ll>
#define vii vector<pair<ll,ll>>
ll mod=1e9+7;
// ll n=1;
vector<int> parent(1,0);
vector<int> sizee(1,1);
vector<vector<int>> adj(1);
void solve(){
    int n,w;
    cin>>n>>w;
    vi weight(n);
    vi v(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>weight[i];
        cin>>v[i];
        sum+=v[i];
    }
    vector<vector<ll>> ans(n+1,vector<ll> (sum+1,1e15));
    // for(int i=0;i<sum+1;i++){
    //     ans[0][i]=0;
    // }
    for(int i=0;i<n+1;i++){
        ans[i][0]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=sum;j>0;j--){
            ans[i][j]=min(ans[i-1][j],weight[i-1]+ans[i-1][max(j-v[i-1],ll(0))]);
        }
    }
    // for(auto k:ans){
    //     for(auto d:k){
    //         cout<<d<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int i=sum;i>0;i--){
        if(ans[n][i]<=w){cout<<i;return;}
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
