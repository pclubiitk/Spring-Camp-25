<<<<<<< HEAD
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
    vector<vector<bool>> visited(n+2,vector<bool>(m+2,0));
    vector<vector<vector<pair<ll,ll>>>> v(n+2,vector<vector<pair<ll,ll>>>(m+2));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
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
    ll ans=0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(visited[i][j]==1 || in[i][j]=='#'){continue;}
            ans++;
            queue<pair<ll,ll>> q;
            q.push({i,j});
            visited[i][j]=1;
            while(!q.empty()){
                pair<ll,ll> u=q.front();
                q.pop();
                for(auto o:v[u.first][u.second]){
                    if(!visited[o.first][o.second]){
                        visited[o.first][o.second]=1;
                        q.push(o);
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
=======
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
    vector<vector<bool>> visited(n+2,vector<bool>(m+2,0));
    vector<vector<vector<pair<ll,ll>>>> v(n+2,vector<vector<pair<ll,ll>>>(m+2));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
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
    ll ans=0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(visited[i][j]==1 || in[i][j]=='#'){continue;}
            ans++;
            queue<pair<ll,ll>> q;
            q.push({i,j});
            visited[i][j]=1;
            while(!q.empty()){
                pair<ll,ll> u=q.front();
                q.pop();
                for(auto o:v[u.first][u.second]){
                    if(!visited[o.first][o.second]){
                        visited[o.first][o.second]=1;
                        q.push(o);
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
>>>>>>> e1e81325a0214cdad8e7d97b97ce6270d16146d2
}