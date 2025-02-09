#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll mod=1e9+7;
void solve() {
    ll n,m;
    cin>>n>>m;
    vector<string> v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    vector<vector<ll>> ans(n+1,vector<ll>(m+1,0));
    ans[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // cout<<" kk\n";
            if(i==1 && j==1){continue;}
            if(v[i-1][j-1]=='#'){continue;}
            ans[i][j]=(ans[i-1][j]+ans[i][j-1])%mod;
        }
    }
    cout<<ans[n][m]<<"\n";
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}