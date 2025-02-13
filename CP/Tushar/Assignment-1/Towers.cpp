#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        // v[i]=1;
    }
    multiset<ll> s;
    for(int i=0;i<n;i++){
        auto it=s.upper_bound(v[i]);
        if(it==s.end()){s.insert(v[i]);}
        else{
            s.erase(it);
            s.insert(v[i]);
        }
    }
    cout<<s.size()<<endl;
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}