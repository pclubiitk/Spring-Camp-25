#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();

    int test = 1;
    //cin >> test;
    while(test--) {
        int n,k;
        cin>>n>>k;
        if(n==1){
            cout<<0<<endl;
            return 0;
        }
        vi num(n);
        for(int i = 0; i<n; i++){
            cin>>num[i];
        }
        vi dp(n,INT_MAX);
        dp[0] = 0;

        // dp[1] = abs(num[1]-num[0]);
        // for(int i = 2; i<min(k,n); i++){
        //     int mini = 1000000;
        //     for(int j = 0; j<i; j++){
        //         mini = min(mini,dp[j]+abs(num[i]-num[j]));
        //     }
        //     dp[i] = mini;
        // }

        // for(int i = k; i<n; i++){
        //     int mini = 1000000;
        //     for(int j = i-k; j<i; j++){
        //          mini = min(mini,dp[j]+abs(num[i]-num[j]));
        //     }
        //     dp[i] = mini;
        // }

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<=i+k; j++){
                if(j<n)
                dp[j] = min(dp[j],dp[i]+abs(num[i]-num[j]));
            }
        }
        
        cout<<dp[n-1]<<endl;
    }

    return 0;
}










