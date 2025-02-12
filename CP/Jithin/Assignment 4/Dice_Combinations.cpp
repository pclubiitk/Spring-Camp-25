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
    // Use Complete knapsack instead of Knapsack 0-1 (Refer CP algo) as the coins/values can be reused any number of times.
    int n;
    cin>>n;
    vll dp(n+1); // No: of ways to construct sum=i;
    dp[0]=1;
    vi w={1,2,3,4,5,6};
    rep(j,1,n){ // For each sum from 1 to n
        rep(i,0,5){ // Use all face of dice. 
            if(w[i]>j) continue;
            dp[j]+=dp[j-w[i]];
            dp[j]%=MOD;
        }
    }
    cout<<dp[n];
    return 0;
}