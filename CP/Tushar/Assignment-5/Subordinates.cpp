#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll mod=1e9+7;
void f(stack<ll> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<" gg\n";
}
void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> adj(n+1);
    for(ll i=0;i<n-1;i++){
        ll j;
        cin>>j;
        adj[i+2].push_back(j);
        adj[j].push_back(i+2);
    }
    vector<ll> visited(n+1,0);
    stack<ll> s;
    vector<pair<ll,ll>> y(n+1,{0,0});
    s.push(1);
    visited[1]=true;
    ll time=1;
    vector<ll> parent(n+1,-1);
    ll idx=0;
    while(!s.empty()){
        // f(s);
        ll u=s.top();
        s.pop();
        if(y[u].first==0){
            y[u].first=time;
            time++;
        }
        else{
            ll p=0;
            for(auto l:adj[u]){
                if(l==parent[u]){continue;}
                if(visited[l]!=2){p++;break;}
            }
            if(p==0){
                y[u].second=time;
                time++;
                if(u==1){break;}
                visited[u]=2;
                s.push(parent[u]);
            }
            // cout<<u<<" pp\n";
            continue;
            // idx++;
        }
        ll o=0;
        for(auto &v:adj[u]){
            if(!visited[v]){
                s.push(v);
                visited[v]=1;
                o++;
                parent[v]=u;
            }
        }
        if(o==0){
            y[u].second=time;
            time++;
            visited[u]=2;
            s.push(parent[u]);
        }
    }
    for(int i=1;i<n+1;i++){
        cout<<(y[i].second-y[i].first)/2<<" ";
    }
    cout<<"\n";
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}