
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
// ll n=1;
vector<int> parent(1,0);
vector<int> sizee(1,1);
vector<vector<int>> adj(1);
int getparent(int a){
    if(parent[a]==a){return a;}
    return parent[a]=getparent(parent[a]);
}
void unite(int a,int b){
    a=getparent(a);
    b=getparent(b);
    if(a==b){return;}
    if(sizee[a]>sizee[b]){swap(a,b);}
    sizee[b]+=sizee[a];
    parent[a]=b;
}
int solve(){
    int n,m;
    cin>>n>>m;
    parent.resize(n+1,0);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    sizee.resize(n+1,1);
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        if(x==0){continue;}
        int e;
        cin>>e;
        e=getparent(e);
        for(int j=1;j<x;j++){
            int a;
            cin>>a;
            unite(e,a);
        }
    }
    for(int i=1;i<=n;i++){
        int z=getparent(i);
        cout<<sizee[z]<<" ";
    }
    cout<<"\n";
}
int main(){
    int t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
