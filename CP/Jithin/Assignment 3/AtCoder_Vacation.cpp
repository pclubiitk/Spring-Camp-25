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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi a(n),b(n),c(n);
    rep(i,0,n-1) cin>>a[i]>>b[i]>>c[i];
    vector<vector<ll>> dp(n,vector<ll>(3));
    dp[0][0]=a[0]; // Does a on day 0
    dp[0][1]=b[0]; // Does b on day 0
    dp[0][2]=c[0]; // Does c on day 0
    rep(i,1,n-1){
        dp[i][0]=max(dp[i-1][1]+a[i],dp[i-1][2]+a[i]);
        dp[i][1]=max(dp[i-1][0]+b[i],dp[i-1][2]+b[i]);
        dp[i][2]=max(dp[i-1][0]+c[i],dp[i-1][1]+c[i]);
    }
    cout<< max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    return 0;
}