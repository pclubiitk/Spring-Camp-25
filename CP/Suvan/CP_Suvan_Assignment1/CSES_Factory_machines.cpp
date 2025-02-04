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
    // cin >> test;
    while(test--) {
        long long n;
        long long tar;
        cin >> n >> tar;
        vi num(n);
        for(int i = 0; i < n; i++) {
            cin >> num[i];
        }
        sort(all(num));
 
        long long l = 0, r = num[0] * tar;
        
        while(l<=r){
            long long mid = (l + r) / 2;
            long long cnt = 0;
 
            for (int i = 0; i < n; i++) {
                cnt += mid / num[i];
            }
 
            if (cnt >= tar) {
                r = mid-1;  
            } else {
               l = mid+1;  
            }
        }
 
        cout << l << endl;
    }
 
    return 0;
}
 