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
        int n;
        cin>>n;
        vi num(n);
        set<int> ans;
        for(int i = 0; i<n; i++){
            cin>>num[i];
            ans.insert(num[i]);
        }
        long long sum = accumulate(all(num),0);
        vector<bool> dp(sum+1,false);
        dp[0] = true;
        for(int i = 0; i<n; i++){
            for(int j = sum; j>=num[i]; j--){
                if(dp[j-num[i]]){
                    dp[j] = true;
                }
            }
        }

        for(int i = 1; i<=sum; i++){
            if(dp[i]) ans.insert(i);
        }
        cout<<ans.size()<<endl;
        for(auto it : ans){
            cout<<it<<" ";
        }
    }

    return 0;
}

