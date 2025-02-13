
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll mod=1e9+7;
// ll n=1;
vector<int> parent(1,0);
vector<int> sizee(1,1);
vector<vector<int>> adj(1);
void solve(){
    int n,x;
    cin>>n>>x;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<bool> check(x+1,0);
    vector<ll> ways(x+1,0);
    ways[0]=1;
    check[0]=1;
    for(int i=0;i<n;i++){
        for(int j=v[i];j<x+1;j++){
            if(ways[j-v[i]]>0){
                {ways[j]=(ways[j-v[i]]+ways[j])%mod;}
            }
        }
        // for(auto k:check){cout<<k<<" ";}
        // cout<<" pp\n";
    }
    // for(auto k:ways){cout<<k<<" ";}
    // cout<<" pp\n";
    cout<<ways[x];
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
