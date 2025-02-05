#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

ll total(vi& mac,ll time){
    ll sum=0;
    for(int& el: mac){
        sum+=time/el;
        if(sum<0){
            return LONG_LONG_MAX;
        }
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll l=1,r=1e18;
    int n,t;
    cin>>n>>t;
    vi mac(n);
    rep(i,0,n-1) cin>>mac[i];
    while(l<r-1){
        ll mid=(l+r)/2;
        ll sum=total(mac,mid);
        if(sum>=t){
            r=mid;
        } else l=mid;
    }
    if(total(mac,l)==t) cout<<l;
    else cout<<r;
    return 0;
}