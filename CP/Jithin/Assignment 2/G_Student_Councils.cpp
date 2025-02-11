#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

bool isPos(vi& a,int k, ll num){
    ll sum=0;
    for(int& el: a){
        sum+=min(num,(ll)el);
    }
    return sum>=num*k;
}

void solve(){
    int k,n;
    cin>>k>>n;
    vi a(n);
    rep(i,0,n-1) cin>>a[i];
    ll l=0; ll r=1e11;
    ll ans;
    while(l<=r){
        ll mid=(l+r)/2;
        bool val=isPos(a,k,mid);
        if(val){
            ans=mid;
            l=mid+1;
        } else r=mid-1;
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}