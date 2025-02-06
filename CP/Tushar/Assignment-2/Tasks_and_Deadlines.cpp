#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
void solve() {
    ll n;
    cin>>n;
    ll d=0;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        ll x;
        cin>>v[i]>>x;
        d+=x;
    }
    sort(v.begin(),v.end());
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];;
        d-=sum;
    }
    cout<<d<<"\n";
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}