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
        string s1,s2;
        cin>>s1>>s2;
        int a = s1.size(), b= s2.size();
        vector<vi > dp(a+1,vi(b+1,0));
        for(int i = 1; i<=a; i++){
            for(int j = 1; j<=b; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string ans = "";
        int i = a, j = b;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans = s1[i-1] + ans;
                i--;
                j--;
            }
            else if(dp[i-1][j]>=dp[i][j-1]) i--;
            else j--;
        }
        cout<<ans<<endl;
    }

    return 0;
}

