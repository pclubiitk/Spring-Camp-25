#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<bool> v(1e5+3);
    v[0]=1;
    ll count=0;
    for(int i=0;i<n;i++){
        // cout<< "ok\n";
        for(int j=1e5+2;j>=0;j--){
            if( j-a[i]>=0 && v[j]==0 && v[j-a[i]]==1){v[j]=1;count++;}
        }
    }
    cout<<count<<endl;
    for(int i=1;i<v.size();i++){
        if(v[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}