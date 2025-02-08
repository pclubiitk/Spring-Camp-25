
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
	vector<bool> visited(n+1,0);
    vector<int> parent(n+1,-1);
    vector<int> distance(n+1,-1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<ll> q;
    q.push(1);
    visited[1]=1;
    while(!q.empty()){
        ll node=q.front();
        q.pop();
        for(auto k:v[node]){
            if(!visited[k]){
                q.push(k);
                visited[k]=1;
                parent[k]=node;
                distance[k]=distance[node]+1;
            }
        }
    }
    // }
    if(distance[n]==-1){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    vector<ll> ans;
    ll idx=n;
    while( parent[idx]!=-1){
        ans.push_back(idx);
        idx=parent[idx];
    }
    ans.push_back(1);
    cout<<ans.size()<<endl;
    for(int i=ans.size()-1; i>=0; i--){
        // cout<<k<<" ";
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
