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
    cin >> test;
    while(test--) {
        int n,c;
        cin>>n>>c;
        vector<long long> num(n);
        long long ans;
        for(int i = 0; i<n; i++){
            cin>>num[i];
        }
        sort(all(num));
        long long r = num[n-1]-num[0];
        long long l = 1;
        while(l<=r){
            long long mid = (l+r)/2;
            int placed = 1;
            int last = num[0];
            for(int i = 0; i<n; i++){
                if(num[i]-last>=mid){
                    placed++;
                    last =  num[i];
                }
                if(placed==c) break;
            }
            if(placed>=c){
                ans = mid;
                l = mid + 1;
            }
            else r = mid-1;
        }
        cout<<r<<endl;
    }

    return 0;
}