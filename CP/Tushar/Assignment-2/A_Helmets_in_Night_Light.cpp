#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
void solve() {
    ll n,p;
    cin>>n>>p;
    vector<pair<ll,ll>> a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i].second=x;
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i].first=x;
    }
    sort(a.begin(),a.end());
    ll ple=0;
    ll cost=0;
    cost+=p;
    ple++;
    for(int i=0;i<n;i++){
        if(ple>=n){break;}
        if(a[i].first>=p){
            cost+=(n-ple)*p;
            break;
        }
        else{
            ll num=min(n-ple,a[i].second);
            cost+=num*a[i].first;
            ple+=num;
        }
    }
    cout<<cost<<"\n";return;
}
int main(){
    ll t;
    t=1;
    cin>>t;
    while(t--){
        solve();
    }
}