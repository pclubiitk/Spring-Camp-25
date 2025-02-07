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
    vector<vector<char>> in(n+2,vector<char>(m+2,'#'));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            cin>>in[i][j];
        }
    }
    // cout<<" okk\n";
    vector<vector<bool>> visited(n+2,vector<bool>(m+2,0));
    vector<vector<pair<ll,ll>>> parent(n+2,vector<pair<ll,ll>>(m+2,{-1,-1}));
    vector<vector<vector<pair<ll,ll>>>> v(n+2,vector<vector<pair<ll,ll>>>(m+2));
    pair<ll,ll> start;
    pair<ll,ll> end;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(in[i][j]=='A'){start={i,j};}
            if(in[i][j]=='B'){end={i,j};}
            if(in[i-1][j]=='.' || in[i-1][j]=='B'){
                v[i][j].push_back({i-1,j});
            }
            if(in[i+1][j]=='.' || in[i+1][j]=='B'){
                v[i][j].push_back({i+1,j});
            }
            if(in[i][j-1]=='.' || in[i][j-1]=='B'){
                v[i][j].push_back({i,j-1});
            }
            if(in[i][j+1]=='.' || in[i][j+1]=='B'){
                v[i][j].push_back({i,j+1});
            }
        }
    }
    queue<pair<ll,ll>> q;
    q.push(start);
    visited[start.first][start.second]=1;
    while(!q.empty()){
        pair<ll,ll> u=q.front();
        q.pop();
        for(auto o:v[u.first][u.second]){
            if(!visited[o.first][o.second]){
                visited[o.first][o.second]=1;
                parent[o.first][o.second]=u;
                q.push(o);
            }
        }
    }
    if(visited[end.first][end.second]==0){
        cout<<"NO\n";
        return;
    }
    else{
        cout<<"YES\n";
    }
    pair<ll,ll> j=end;
    vector<pair<ll,ll>> ans;
    while(j.first+j.second!=-2){
        ans.push_back(j);
        j=parent[j.first][j.second];
    }
    // ans.push_back(start);
    cout<<ans.size()-1<<endl;
    // for(auto k:ans){
    //     cout<<k.first<<" "<<k.second<<"\n";
    // }
    string g;
    for(int i=ans.size()-2;i>=0;i--){
        if(ans[i+1].first+1==ans[i].first){
            g.append("D");
        }
        else if(ans[i+1].first-1==ans[i].first){
            g.append("U");
        }
        else if(ans[i+1].second+1==ans[i].second){
            g.append("R");
        }
        else{
            g.append("L");
        }
    }
    cout<<g<<"\n";
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}