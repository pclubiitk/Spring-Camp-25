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
    int n;
    cin>>n;
    vvi a(n,vi (n));
    rep(i,0,n-1) rep(j,0,n-1) cin>>a[i][j];
    vi dp(1<<n); // The bitmask acts as the index which indicates which all women have been paired already. 
    //The number of 1s in the mask indicate the count of men and women paired already.
    //dp[mask] gives the no: of possible pairings for the given mask;
    dp[0]=1;
    rep(i,0,(1<<n)-1){
        int matched=__builtin_popcount(i);
        //start with matched th man (0 based indexing).
        // Check all women
        rep(j,0,n-1){
            if(((i&(1<<j))==0) && a[matched][j]){ // jth woman is not matched yet and matched th man is compatible with jth woman.
                int newState=i|(1<<j); // Make jth woman matched.
                dp[newState]+=dp[i];
                dp[newState]%=MOD;
            }
        }
    }
    cout<<dp[(1<<n)-1];
    return 0;
}