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
        int n,q;
        cin>>n>>q;
        vector<long long> num(q);
        for(int i = 0; i<q; i++){
            cin>>num[i];
            num[i] -= 1;
        }
        vector<long long> res;
        long long l = num[0];
        long long r = 0;
        long long p = max(abs(n-1-num[0]),abs(num[0]+1));
        res.push_back(p);
        if(num[0]<n/2) r = n-1;
        else{
            l = 0;
            r = num[0];
        }
        for(int i = 1; i<q; i++){
            long long chk = num[i];
            if(chk>l && chk<r){
                if(chk<=(l+r)/2){
                    res.push_back(r-chk);
                    l = chk;
                    p = r- chk;
                }
                else{
                    res.push_back(chk-l);
                    r = chk;
                    p = chk - l;
                }
            }
            else{
                res.push_back(p);
            }
        }
        for(int i = 0; i<q; i++){
            cout<<res[i]<<" ";
        }
    }
 
    return 0;
}