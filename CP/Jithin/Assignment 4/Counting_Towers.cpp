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

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    vi a(t);
    rep(i,0,t-1){
        cin>>a[i];
    }
    int n=*max_element(a.begin(),a.end());
    vvll dp(n+1,vll (2));
    // dp[i][0] represents towers of length i ending with separate cells on top and dp[i][1] represent towers of length i
    // ending with joint cell on top;
    dp[1][0]=1;
    dp[1][1]=1;
    rep(i,2,n){
        dp[i][0]=(4*dp[i-1][0]+dp[i-1][1])%MOD;
        dp[i][1]=(dp[i-1][0]+2*dp[i-1][1])%MOD;
    }
    for(int el: a){
        cout<<(dp[el][0]+dp[el][1])%MOD<<"\n";
    }
    return 0;
}