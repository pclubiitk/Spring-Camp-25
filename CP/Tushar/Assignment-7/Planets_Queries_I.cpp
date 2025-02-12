#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>
#define pr pair<ll,ll>
#define vii vector<pair<ll,ll>>
ll mod=1e9+7;
vector<int> sizee(1,1);
vector<int> visited(1,0);
vector<vector<int>> adj(1);
void solve(){
    int n,q;
    cin>>n>>q;
    adj.resize(n+1);
    vector<ll> child(n+1,0);
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        adj[i].push_back(a);
        child[i]=a;
    }
    ll z=log2(n)+1;
    vector<vector<ll>> up(n+1,vector<ll>(z));
    for(int i=1;i<n+1;i++){
        up[i][0]=child[i];
    }
    for(auto k:child){
        cout<<k<<" ";
    }
    cout<<" jj\n";
    for(int i=1;i<z;i++){
        for(int j=1;j<n+1;j++){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }
    for(int i=0;i<q;i++){
        ll start,steps;
        cin>>start>>steps;
        for(int j=0;j<z;j++){
            if(steps&(1<<j)){
                start=up[start][j];
            }
        }
        cout<<start<<"\n";
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
