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

vvll mult(vvll m1, vvll m2){
    vvll ans(2,vll (2));
    ans[0][0]=((m1[0][0]*m2[0][0])%MOD+(m1[0][1]*m2[1][0])%MOD)%MOD;
    ans[0][1]=((m1[0][0]*m2[0][1])%MOD+(m1[0][1]*m2[1][1])%MOD)%MOD;
    ans[1][0]=((m1[1][0]*m2[0][0])%MOD+(m1[1][1]*m2[1][0])%MOD)%MOD;
    ans[1][1]=((m1[1][0]*m2[0][1])%MOD+(m1[1][1]*m2[1][1])%MOD)%MOD;
    return ans;
}

vvll binExp(vvll base, ll pow){
    vvll ans={{1,0},{0,1}};
    while(pow>0){
        if(pow&1){
            ans=mult(ans,base);
        }
        base=mult(base,base);
        pow>>=1;
    }
    return ans;
}

void solve(){
    int n,m;
    cin>>n>>m;
    // f(m+2)-f(n+1)
    vvll m1=binExp({{1,1},{1,0}},m+1);
    vvll m2=binExp({{1,1},{1,0}},n);
    ll fm=(m1[0][0]*1+m1[0][1]*0)%MOD;
    ll fn=(m2[0][0]*1+m2[0][1]*0)%MOD;
    cout<<(fm-fn+MOD)%MOD<<"\n"; // fm-fn can be negative
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}