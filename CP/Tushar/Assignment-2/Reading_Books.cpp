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
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ll sum=0;
    for(int i=0;i<n-1;i++){
        sum+=v[i];
    }
    if(sum>=v[n-1]){
        cout<<sum+v[n-1]<<endl;return;
    }
    cout<<sum+v[n-1]-sum+v[n-1]<<endl;
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}