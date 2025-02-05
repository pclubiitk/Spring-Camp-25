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
long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main() {
    fast_io();

    int test = 1;
    //cin >> test;
    while(test--) {
        int n;
        cin>>n;
        vi num(n);
        for(int i = 0; i<n; i++){
            cin>>num[i];
        }
        vector<long long> pre(n), suff(n);
        pre[0] = num[0];
        suff[n-1] = num[n-1];
        for(int i = 1; i<n; i++){
            pre[i] = gcd(pre[i-1],num[i]);
        }
        for(int i = n-2; i>=0; i--){
            suff[i] = gcd(suff[i+1],num[i]);
        }
        long long ans = 0;
        for(int  i = 0; i<n; i++){
            long long cur;
            if(i==0) cur = suff[1];
            else if(i==n-1) cur = pre[n-2];
            else cur = gcd(pre[i-1],suff[i+1]);
            ans = max(ans,cur);
        }
        cout<<ans<<endl;
    }

    return 0;
}