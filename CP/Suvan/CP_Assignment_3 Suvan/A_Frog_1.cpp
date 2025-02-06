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
    while(test--){
        int n;
        cin>>n;
        vi num(n);
        for(int i = 0; i<n; i++){
            cin>>num[i];
        }
        int dp[n];
        dp[0] = 0;
        dp[1] = abs(num[1]-num[0]);
        for(int i = 2; i<n; i++){
            dp[i] = min((dp[i-2]+ abs(num[i]-num[i-2])),(dp[i-1]+abs(num[i]-num[i-1])));
        }
        cout<<dp[n-1]<<endl;
    }

    return 0;
}