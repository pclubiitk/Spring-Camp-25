#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>;
#define pr pair<ll,ll>;
#define vii vector<pair<ll,ll>;
void solve() {
    ll n;
    cin>>n;
    vector<ll> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    ll ans[n+5];
    ans[0]=0;
    if(v[0]==1){ans[1]=1;}
    else{
        ans[1]=0;
    }
    for(int i=2;i<n+5;i++){
        ll temp=1000000000000000;
        if(i>1){
            ll u=0;
            if(v[i-1-1]==1){u++;}
            temp=min(temp,u+ans[i-2]);
        }
        if(i>2){
            ll u=0;
            if(v[i-1-1]==1){u++;}
            if(v[i-2-1]==1){u++;}
            temp=min(temp,u+ans[i-3]);
            u=0;
            if(v[i-2-1]==1){u++;}
            temp=min(temp,u+ans[i-3]);
        }
        if(i>3){
            ll u=0;
            if(v[i-2-1]==1){
                u++;
            }
            if(v[i-3-1]==1){
                u++;
            }
            temp=min(temp,u+ans[i-4]);
        }
        ans[i]=temp;
    }
    // for(auto h:ans){
    //     cout<<h<<" ";
    // }
    // cout<<endl;
    ll k=100000000000000;
    k=min(ans[n],k);
    k=min(ans[n+1],k);
    k=min(ans[n+2],k);
    k=min(ans[n+3],k);
    k=min(ans[n+4],k);
    cout<<k<<endl;
}
int main(){
    ll t;
    t=1;
    cin>>t;
    while(t--){
        solve();
    }
}