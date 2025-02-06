#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
ll mod=1e9+7;
vector<ll> fac(20000001,1);
ll factorial(){
    for(int i=1;i<20000001;i++){
        fac[i]=(i*(fac[i-1]))%mod;
    }
}
ll qua(ll n){
    double ans=0;
    double left=0;
    double right=1e13;
    for(int i=0;i<100;i++){
        // cout<<left<<" "<<right<<endl;
        ll mid=(left+right)/2;
        if(mid>1e7){right=mid;continue;}
        if(mid*(mid+1)/2-1<=n){
            left=mid;
            ans=left;
        }
        else{
            right=mid;
        }
    }
    return ans;
}
void solve() {
    ll n;
    cin>>n;
    ll j=qua(n);
    ll h=n-(j*(j+1)/2-1);
    cout<<(fac[j]*max(h,ll(1)))%mod<<endl;
}
int main(){
    ll t;
    factorial();
    t=1;
    cin>>t;
    while(t--){
        solve();
    }
}