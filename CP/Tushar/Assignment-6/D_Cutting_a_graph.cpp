
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
// ll n=1;
vector<ll> parent(1,0);
ll getparent(int a){
    if(parent[a]==a){return a;}
    return parent[a]=getparent(parent[a]);
}
void unite(int a,int b){
    a=getparent(a);
    b=getparent(b);
    if(a!=b){
        parent[a]=b;
    }
}
vector<vector<ll>> adj(1);
void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    adj.resize(n+1);
    parent.resize(n+1);
    for(int i=0;i<n+1;i++){
        parent[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
    }
    vector<tuple<char,ll,ll>> v(k);
    for(int i=k-1;i>=0;i--){
        string s;
        cin>>s;
        int x,y;
        cin>>x>>y;
        v[i]=make_tuple(s[0],x,y);
    }
    vector<string> ans;
    for(int i=0;i<k;i++){
        char c;
        ll a,b;
        tie(c,a,b)=v[i];
        if(c=='a'){
            if(getparent(a)==getparent(b)){
                ans.push_back("YES");
            }
            else{
                ans.push_back("NO");
            }
        }
        else{
            unite(a,b);
        }
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<"\n";
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
