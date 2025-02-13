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
        vi num(n);
        for(int i = 0; i<n; i++){
            cin>>num[i];
        }
        sort(num.rbegin(),num.rend());
        vi fre(n+1,0);
        for(int i = 0; i<q; i++){
            int a,b;
            cin>>a>>b;
            fre[a-1]++;
            if(b<n){
                fre[b]--;
            }
        }
        for(int i = 1; i<n; i++){
            fre[i] +=fre[i-1];
        }

        vi f(fre.begin(),fre.begin()+n);
        sort(f.rbegin(),f.rend());
        long long res = 0;
        for(int i = 0; i<f.size(); i++){
            res += (long long)f[i]*num[i];
        }
        cout<<res<<endl;

    }

    return 0;
}
