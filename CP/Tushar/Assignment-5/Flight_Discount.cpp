#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>
#define pr pair<ll,ll>
#define vii vector<pair<ll,ll>
ll mod=1e9+7;
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }
    vector<vector<ll>> distance(n+1,vector<ll>(2,LLONG_MAX));
    distance[1][0]=0;
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>> ,greater<tuple<ll,ll,ll>>> pq;
    pq.push({0,1,0});
    ll idx=0;
    while(!pq.empty()){
        // print_queue(pq);
        // print_vector(distance);
        ll cost,node,discount;
        tie(cost,node,discount)=pq.top();
        pq.pop();
        if(cost>distance[node][discount]){;continue;}
        for(auto neighbor:adj[node]){
            ll to=neighbor.first;
            ll weight=neighbor.second;
            ll ncost=cost+weight;
            if(discount==1){
                if(ncost<distance[to][1]){
                    distance[to][1]=ncost;
                    pq.push({ncost,to,1});
                }
            }
            else{
                if(ncost<distance[to][0]){
                    distance[to][0]=ncost;
                    pq.push({ncost,to,0});
                }
                if(ncost-weight+weight/2<distance[to][1]){
                    pq.push({ncost-weight+weight/2,to,1});
                    distance[to][1]=ncost-weight+weight/2;
                }
            }
        }
        idx++;
    }
    cout<<distance[n][1]<<endl;
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