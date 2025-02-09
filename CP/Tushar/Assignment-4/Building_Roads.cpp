
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
    vector<vector<ll>> v(n+1);
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool> visited(n+1,0);
    bool check=false;
    ll idx=1;
    vector<pair<ll,ll>> ans;
    ll o=0;
    for(int i=1;i<n+1;i++){
        if(!visited[i]){
            if(check){
                // cout<<i<<" "<<idx<<endl;
                ans.push_back({idx,i});
                idx=i;
                o++;
            }
            queue<ll> q;
            q.push(i);
            visited[i]=1;
            while(!q.empty()){
                ll node=q.front();
                q.pop();
                for(auto x:v[node]){
                    if(!visited[x]){
                        q.push(x);
                        visited[x]=1;
                    }
                }
            }
        }
        check=true;
    }
    cout<<o<<"\n";
    for(int i=0;i<o;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
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
