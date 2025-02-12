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
    vi x(n+1);
    int sum=0;
    rep(i,1,n){
        int y;
        cin>>y;
        sum+=y;
        x[i]=y;
    }
    vvi dp(sum+1,vi (n+1)); // dp[i][j] is 1 if when considering the first j coins, sum i is possible.
    dp[0][0]=1;
    int count=-1;
    rep(j,1,n){
        rep(i,0,sum){
            if(x[j]>i){
                dp[i][j]=dp[i][j-1];
            } else {
                dp[i][j]=dp[i-x[j]][j-1]|dp[i][j-1];
            }
            if(j==n){
                count+=dp[i][n];
            }
        }

    }
    cout<<count<<"\n";
    rep(i,1,sum){
        if(dp[i][n]) cout<<i<<' ';  
    }
    return 0;
}