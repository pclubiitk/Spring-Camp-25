#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> v;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        vector<ll> j;
        j.push_back(x);
        j.push_back(y);
        j.push_back(z);
        v.push_back(j);
    }
    ll ans[n][3];
    ans[0][0]=v[0][0];
    ans[0][1]=v[0][1];
    ans[0][2]=v[0][2];
    for(int i=1;i<n;i++){
        ans[i][0]=max(ans[i-1][1],ans[i-1][2])+v[i][0];
        ans[i][1]=max(ans[i-1][0],ans[i-1][2])+v[i][1];
        ans[i][2]=max(ans[i-1][0],ans[i-1][1])+v[i][2];
    }
    cout<<max(ans[n-1][0],max(ans[n-1][1],ans[n-1][2]))<<"\n";
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}