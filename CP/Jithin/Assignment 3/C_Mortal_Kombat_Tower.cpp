#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

bool val(char c){
    if(c=='1') return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<char> boss(n);
        rep(i,0,n-1) cin>>boss[i];
        // 0 friend and 1 us
        //dp[k][0] represents kth(0 indexing) boss killed by friend
        vector<vi> dp(n,vi(2));
        dp[0][0]=val(boss[0]);
        dp[0][1]=INT_MAX;
        dp[1][0]=dp[0][0]+val(boss[1]);
        dp[1][1]=dp[0][0];
        rep(i,2,n-1){
            if(i==2){
                dp[i][0]=dp[i-1][0]+val(boss[i]);
            } else {
                dp[i][0]=min(dp[i-2][1]+val(boss[i-1])+val(boss[i]),dp[i-1][0]+val(boss[i]));
            }
            dp[i][1]=min(dp[i-2][0],dp[i-1][0]);
        }
        cout<<min(dp[n-1][0],dp[n-1][1]) << "\n";
    }
    return 0;
}