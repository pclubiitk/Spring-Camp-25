#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
void solve() {
    string s;
    cin>>s;
    ll n=s.size();
    vector<ll> v;
    v.push_back(1);
    map<ll,ll> m;
    m[1]++;
    for(int i=1;i<n+1;i++){
        int x=v[i-1]^s[i-1];
        v.push_back(x);
        m[x]++;
    }
    ll sum=0;

    for(auto h:m){
        ll k=h.second;
        sum+=k*(k-1)/2;
    }
    cout<<sum<<endl;
}
int main(){
    ll t;
    t=1;
    cin>>t;
    while(t--){
        solve();
    }
}