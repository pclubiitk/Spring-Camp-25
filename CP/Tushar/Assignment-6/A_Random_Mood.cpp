
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll mod=1e9+7;
vector<vector<double>> matrix_mul(vector<vector<double>> a,vector<vector<double>> b){
    ll n=a.size();
    vector<vector<double>> c(n,vector<double>(n,0));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            for(ll k=0;k<n;k++){
                c[i][j]=(c[i][j]+a[i][k]*b[k][j]);
            }
        }
    }
    return c;
}
double p;
double g(ll n){
    if(n==0){return 0;}
    vector<vector<double>>ans={{1,0},{0,1}};
    vector<vector<double>>c={{1-p,p},{p,1-p}};
    while(n>0){
        if(n%2==1){
            ans=matrix_mul(ans,c);
            n--;
        }
        else{
            c=matrix_mul(c,c);
            n/=2;
        }
    }
    return ans[1][1];
}
void solve(){
    ll n;
    cin>>n;
    cin>>p;
    cout<<fixed<<setprecision(10)<<g(n);
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
