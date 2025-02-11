#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>
#define pr pair<ll,ll>
#define vii vector<pair<ll,ll>>
ll mod=1e9+7;
// ll n=1;
vector<int> parent(1,0);
vector<int> sizee(1,1);
vector<vector<int>> adj(1);
void solve(){
    ll x,n;
    cin>>x>>n;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(int i=0;i<n;i++){
        ll v;
        cin>>v;
        pq.push(v);
    } 
    ll ans=0;
    for(int i=0;i<n-1;i++){
        ll a=pq.top();
        pq.pop();
        ll b=pq.top();
        pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
