
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll n=1;
vector<ll> parent(n+1,0);
ll change(int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=change(parent[node]);
}
void solve(){
    int n,m;
    cin>>n>>m;
    parent.resize(n+2,0);
    for(int i=0;i<n+2;i++){
        parent[i]=i;
    }
    for(int i=0;i<m;i++){
        // for(auto j:parent){
        //     cout<<j<< " ";
        // }
        // cout<<" pp\n";
        char c;
        cin>>c;
        int x;
        cin>>x;
        if(c=='?'){
            parent[x]=change(x);
            if(parent[x]==n+1){cout<<"-1\n";continue;}
            cout<<parent[x]<<"\n";
        }
        else{
            // ll x=parent[x];
            parent[x]=x+1;
            // ll o=0;
            parent[x]=change(x);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
