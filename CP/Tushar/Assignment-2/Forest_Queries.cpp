#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
void solve() {
    ll n,q;
    cin>>n>>q;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v[i]=s;
    }
    vector<vector<ll>> ans(n+1,vector<ll>(n+1,0));
    for(int i=1;i<n+1;i++){
        ll sum=0;
        for(int j=1;j<n+1;j++){
            if(v[i-1][j-1]=='*'){
                sum++;
            }
            ans[i][j]=sum+ans[max(0,i-1)][j];
        }
    }
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<n+1;j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<" ok\n";
    for(int i=0;i<q;i++){
        ll x1,x2,y1,y2;
        cin>>y1>>x1>>y2>>x2;
        // cout<<ans[y2][x2]<<" "<<ans[y1-1][x1-1]<<" "<<ans[y1-1][x2]<<" "<<ans[y2][x1-1]<<" ll\n";
        ll t=ans[y2][x2]+ans[y1-1][x1-1]-ans[y1-1][x2]-ans[y2][x1-1];
        cout<<t<<"\n";
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