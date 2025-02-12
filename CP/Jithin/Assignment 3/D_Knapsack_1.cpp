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
    int n,W;
    cin>>n>>W;
    vll v(n+1);
    vi w(n+1);
    rep(i,1,n) cin>>w[i]>>v[i];
    vvll dp(n+1,vll (W+1)); // dp[i][j] represents the max value when first i elements are considered and weight is atmost j.
    rep(i,1,n){
        rep(j,1,W){
            if(w[i]>j){
                dp[i][j]=dp[i-1][j];
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[n][W];
    return 0;
}