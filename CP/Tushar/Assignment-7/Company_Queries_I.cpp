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
    vector<ll> parent;
    parent.push_back(0);
    parent.push_back(1);
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        parent.push_back(x);
    }
    // for(auto k:parent){
    //     cout<<k<<" ";
    // }
    // cout<<" pp\n";
    ll z=log2(n)+1;
    parent[1]=0;
    parent[0]=0;
    vector<vector<ll>>up(n+1,vector<ll>(z+1));
    for(int i=1;i<n+1;i++){
        up[i][0]=parent[i];
    }
    for(int i=1;i<z;i++){
        for(int j=1;j<=n;j++){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }
    // for(auto k:up){
    //     for(auto o:k){
    //         cout<<o<<" ";
    //     }
    //     cout<<" \n";
    // }
    for(int i=0;i<q;i++){
        int x,k;
        cin>>x>>k;
        ll node=x;
        for(int j=0;j<z;j++){
            if(k &(1<<j)){
                node=up[node][j];
            }
        }
        if(node==0){node=-1;}
        cout<<node<<"\n";
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
