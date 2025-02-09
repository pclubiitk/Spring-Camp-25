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
        vector<long long> num(n);
        for(int i = 0; i<n; i++){
            cin>>num[i];
        }
        sort(num.begin(),num.end());
        long long s = accumulate(all(num),0);
        long long m = num[n-1];
        if(m>s-m)cout<<2*m<<endl;
        else cout<<s<<endl;
    }
    return 0;
}