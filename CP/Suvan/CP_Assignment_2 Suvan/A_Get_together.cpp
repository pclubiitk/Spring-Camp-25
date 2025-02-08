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
        vector<pair<int,int> >num;
        for(int i = 0; i<n; i++){
            int a,b;
            cin>>a>>b;
            num.push_back(make_pair(a,b));
        }
        double l = 0, r = 1e18;
        
        while(r-l>1e-7){
            double mid = (l+r)/2;
            double low = -1e18,high = +1e18;
            for(int i = 0; i<n; i++){
                low = max(low,num[i].first - num[i].second*mid);
                high = min(high,num[i].first + num[i].second*mid);
            }
            if(high>=low) r = mid;
            else l = mid;
        }
        cout << fixed << setprecision(6) << (l + r) / 2 << endl;
    }

    return 0;
}
   