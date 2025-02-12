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

int subtract(string x, char y){
    int ans=stoi(x)-(y-'0');
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int lim=stoi(s);
    vi dp(lim+1);
    dp[0]=0;
    rep(i,1,lim){
        string val=to_string(i);
        dp[i]=INT_MAX;
        for(char c: val){
            dp[i]=min(dp[i],dp[subtract(val,c)]+1);
        }
    }
    cout<<dp[lim];
    return 0;
}