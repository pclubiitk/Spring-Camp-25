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
        long long tar;
        cin>>n>>tar;
        vi num(n);
        for(int i = 0; i<n; i++){
            cin>>num[i];
        }
        long long s = 0;
        long long cnt = 0;
        map<long long, long long> pre;
        pre[0] = 1;
        for(int i = 0; i<n; i++){
            s += num[i];
            if(pre.find(s - tar) != pre.end()){
                cnt += pre[s-tar];
            }
            pre[s]++;
        }
        cout<<cnt<<endl;
    }
 
    return 0;
}