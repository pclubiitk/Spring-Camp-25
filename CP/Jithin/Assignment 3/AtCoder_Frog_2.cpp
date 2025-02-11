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
    int n,k;
    cin>>n>>k;
    vi a(n);
    rep(i,0,n-1) cin>>a[i];
    vector<ll> dp(n);
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);
    rep(i,2,n-1){
        ll minCost=LONG_LONG_MAX;
        int j=i-1;
        while(j>=0 && j>=i-k){
            minCost=min(minCost,dp[j]+abs(a[i]-a[j]));
            --j;
        }
        dp[i]=minCost;
    }
    cout<<dp[n-1];
    return 0;
}