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
        vector<vector<int> > dp(a+1,vector<int> (b+1,0));
        for(int i = 0; i<=b; i++){
            dp[0][i] = i;
        }
        for(int j = 0; j<=a; j++){
            dp[j][0] = j;
        }
        for(int i = 1; i<=a; i++){
            for(int j = 1; j<=b; j++){
                int a = dp[i-1][j-1] +1;
                if(s1[i-1]==s2[j-1]) a -= 1;
                dp[i][j] = min(dp[i-1][j]+1, min(dp[i][j-1]+1,a));
            }
        }
        cout<<dp[a][b]<<endl;
    }

    return 0;
}