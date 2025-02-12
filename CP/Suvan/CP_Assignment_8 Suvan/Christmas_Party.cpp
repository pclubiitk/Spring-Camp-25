#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

const long long MOD = 1e9+7;
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vector<long long> dp;
int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {
        int n;
        cin>>n;
        dp.assign(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i<n; i++){
            dp[i] = i*((dp[i-1]+dp[i-2])%MOD)%MOD;
        }
        cout<<dp[n-1]<<endl;

    }

    return 0;
}