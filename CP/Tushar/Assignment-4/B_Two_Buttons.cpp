
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
ll rec(ll x,ll y){
    if(x>=y){return x-y;}
    if(y%2==0){return 1+rec(x,y/2);}
    return 2+rec(x,(y+1)/2);
}
void solve() {
    ll n,m;
    cin>>n>>m;
    ll start=n;
    ll ans=rec(n,m);
    cout<<ans<<endl;
    return;
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}