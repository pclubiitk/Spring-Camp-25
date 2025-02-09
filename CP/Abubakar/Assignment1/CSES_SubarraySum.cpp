#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
 
int main() {
    FAST
    ll n, k;
    map<ll, ll> mp;
    ll res = 0;
    ll ct = 0;
    mp[0] = 1;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> v[i];
    }
    for(int i = 0; i < n; i++) {
        res += v[i];
        if(mp.find(res - k) != mp.end()) {
            ct += mp[res - k];
        }
        mp[res]++;
    } 
    cout << ct << endl;
}
