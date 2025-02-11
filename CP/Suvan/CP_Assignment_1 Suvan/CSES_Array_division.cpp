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
 
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    long long l = *max_element(arr.begin(), arr.end()); 
    long long r = accumulate(arr.begin(), arr.end(), 0LL); 
 
    long long ans = r;
 
    while (l <= r) {
        long long mid = (l + r) / 2;
 
        long long sum = 0;
        int cnt = 1; 
 
        bool valid = true;
 
        for (int i = 0; i < n; i++) {
            if (sum + arr[i] > mid) {
                cnt++;
                sum = arr[i];
                if (cnt > k) {
                    valid = false;
                    break; 
                }
            } else {
                sum += arr[i];
            }
        }
 
        if (valid) {
            ans = mid;
            r = mid - 1; 
        } else {
            l = mid + 1; 
        }
    }
 
    cout << l << endl;
    return 0;
}
