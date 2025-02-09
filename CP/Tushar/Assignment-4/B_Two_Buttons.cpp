#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll mod=1e9+7;
void f(queue<pair<ll,ll>> q){
    while(!q.empty()){
        cout<<q.front().first<<" ";
        q.pop();
    }
    cout<< " ll\n";
    return;
}
void solve() {
    ll n,m;
    cin>>n>>m;
    ll start=n;
    queue<pair<ll,ll>> q;
    q.push({start,0});
    if(n==m){cout<<"0";return;}
    for(int i=0;;i++){
        ll u=q.front().first;
        ll d=q.front().second+1;
        q.pop();
        if(u-1==m || 2*u==m){cout<<d<<endl;return;}
        if(u-1>=0){q.push({u-1,d});}
        if(u<=2*m){
            q.push({2*u,d});
        }
        f(q);
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