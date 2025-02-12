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
    int h,w;
    cin>>h>>w;
    vector<vector<char>> grid(h+1,vector<char>(w+1));
    rep(i,1,h){
        rep(j,1,w){
            cin>>grid[i][j];
        }
    }
    vvll dp(h+1,vll(w+1));
    dp[1][1]=1;
    rep(i,2,w){
        if(grid[1][i-1]=='.') dp[1][i]=dp[1][i-1];
    }
    rep(i,2,h){
        if(grid[i-1][1]=='.') dp[i][1]=dp[i-1][1];
    }
    rep(i,2,h){
        rep(j,2,w){
            if(grid[i-1][j]=='.'){
                dp[i][j]+=dp[i-1][j];
            }
            if(grid[i][j-1]=='.'){
                dp[i][j]+=dp[i][j-1];
            }
            dp[i][j]%=MOD;
        }
    }
    cout<<dp[h][w];
    return 0;
}