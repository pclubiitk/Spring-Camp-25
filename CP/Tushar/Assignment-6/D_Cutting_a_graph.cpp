
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll n=1;
vector<ll> parent(n+1,0);
ll get(int node){
    if(parent[node]==node){return node;}
    return get(parent[node]);
}
vector<ll> size(n+1,1);
void unite(){
    int a,b;
    cin>>a>>b;
    ll z=get(a);
    ll t=get(b);
    if(t==z){return;}
    parent[b]=a;
    return;
}
void solve(){
    int m,q;
    cin>>n>>m>>q;
    parent.resize(n+1,0);
    size.resize(n+1,1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    for(int i=0;i<m;i++){
        for(auto j:parent){
            cout<<j<<" ";
        }
        cout<<" ll\n";
        unite();
    }
    for(auto j:parent){
        cout<<j<<" ";
    }
    cout<<" ll\n";
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        if(s[0]=='a'){
            int x,y;
            cin>>x>>y;
            if(get(x)==get(y)){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            int x,y;
            cin>>x>>y;
            if(parent[x]==y){
                parent[x]=x;
                size[y]-=size[x];
            }
            else if(parent[y]==x){
                parent[y]=y;
                size[x]-=size[y];
            }
        }
        for(auto j:parent){
            cout<<j<<" ";
        }
        cout<<" ll\n";
    }
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
