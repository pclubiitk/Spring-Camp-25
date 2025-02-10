#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define inf 1e15
const ll MOD = 1000000007;
const ll INF = 1e18;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    vll v;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ll l = 0, r = v.size() - 1, ans = v.size();  
        while (l <= r) {  
            ll mid = (l + r) / 2;
            if (v[mid] >x) {
                ans = mid; 
                r = mid - 1;  
            } else {
                l = mid + 1;
            }
        }
        if (ans == v.size()) v.pb(x);
        else v[ans] = x;
    }
    cout << v.size() << endl;
}
