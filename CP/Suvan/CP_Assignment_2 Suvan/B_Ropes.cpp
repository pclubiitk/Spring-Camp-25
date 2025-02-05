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
        int n,p;
        cin>>n>>p;
        vi num(n);
        for(int i = 0; i<n; i++){
            cin>>num[i];
        }
        double l = 0, r = 10000000;
        while(r-l>1e-7){
            double mid = (l+r)/2.0;
            int pieces = 0;
            for(int i = 0; i<n; i++){
                pieces += num[i]/mid;
            }
            
            if(pieces>=p) l = mid;
            else r = mid;
        
        }
        cout << fixed << setprecision(6) << (l + r) / 2.0 << endl;
    }
    return 0;
}
