#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll qua(ll n){
    double ans=0;
    double left=0,right=1e9;
    for(double i=0;i<100;i++){
        ll mid=(left+right)/2;
        if(mid*(mid+1)/2>n){right=mid;}
        else{
            left=mid;
        }
    }
    left=ll(left);
    return left;
}
void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(int i=0;i<k;i++){
        cin>>v[i];
    }
    ll idx=10000000000000;
    for(int i=k-2;i>=0;i--){
        if(v[i+1]-v[i]>idx){cout<<"No\n";return;}
        else{
            idx=v[i+1]-v[i];
        }
    }
    ll num;
    if(v[0]%(n-k+1)==0){
        num=v[0]/(n-k+1);
    }
    else{num=floor(v[0]/(n-k+1));}
    // cout<<num<<" jj\n";
    if(idx<num){cout<<"No\n";return;}
    cout<<"Yes\n";return;
}
int main(){
    ll t;
    t=1;
    cin>>t;
    while(t--){
        solve();
    }
}