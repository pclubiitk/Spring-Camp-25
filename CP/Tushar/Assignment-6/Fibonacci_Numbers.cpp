#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll mod=1e9+7;
vector<vector<ll>> matrix_mul(vector<vector<ll>> a,vector<vector<ll>> b){
    ll n=a.size();
    vector<vector<ll>> c(n,vector<ll>(n,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            for(ll k=0;k<n;k++){
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
            }
        }
    }
    return c;
}
ll g(ll n){
    if(n==0){return 0;}
    vector<vector<ll>>ans={{1,0},{0,1}};
    vector<vector<ll>>c={{1,1},{1,0}};
    while(n>0){
        if(n%2==1){
            ans=matrix_mul(ans,c);
            n--;
        }
        else{
            c=matrix_mul(c,c);
            n/=2;
        }
        // cout<< " ll\n";
        // for(auto k:ans){
        //     for(auto l:k){
        //         cout<<l<<" ";
        //     }
        //     cout<<"\n";
        // }
    }
    return ans[1][0];
}
void solve(){
    ll n;
    cin>>n;
    cout<<g(n)<<"\n";
    return;  // return from the function solve()
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
