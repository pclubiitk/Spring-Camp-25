#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vdll vector<vector<ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define inf LLONG_MAX
const ll MOD = 1000000007;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
int main() {
    FAST
    ll x, n;
    cin >> x >> n;
    priority_queue<ll> pq;
    for (int i = 0; i < n; i++) {
        ll y;
        cin >> y;
        pq.push(-y);  
    }
 
    ll res = 0;
    for (int i = 1; i < n; i++) {
        ll t1 = -pq.top(); pq.pop();
        ll t2 = -pq.top(); pq.pop();
        res += (t1 + t2);
        pq.push(-(t1 + t2));
    }
 
    cout << res << endl;
}