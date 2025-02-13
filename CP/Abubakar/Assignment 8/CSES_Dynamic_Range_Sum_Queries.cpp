#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vdll vector<vll>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define loop(i, n) for(ll i = 0; i < n; i++)
#define one(i, n) for(ll i = 1; i <= n; i++)
#define ss second
#define all(v) v.begin(), v.end()
#define inf 1e15
#define endl "\n"
#define MOD 1000000007


ll n, q;
vll t;

void build(vll &vec, ll v, ll l1, ll r1) {
    if (l1 == r1) t[v] = vec[l1];
    else {
        ll mid = (l1 + r1) / 2;
        build(vec, 2 * v, l1, mid);
        build(vec, 2 * v + 1, mid + 1, r1);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

ll sum(ll v, ll l1, ll r1, ll l, ll r) {
    if (l > r) return 0;
    if (l == l1 && r == r1) return t[v];
    ll mid = (l1 + r1) / 2;
    return sum(2 * v, l1, mid, l, min(r, mid)) +
           sum(2 * v + 1, mid + 1, r1, max(l, mid + 1), r);
}

void update(ll v, ll l1, ll r1, ll pos, ll newv) {
    if (l1 == r1) t[v] = newv;
    else {
        ll mid = (l1 + r1) / 2;
        if (pos <= mid) update(2 * v, l1, mid, pos, newv);
        else update(2 * v + 1, mid + 1, r1, pos, newv);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    vll vec(n);
    for (ll &x : vec) cin >> x;

    t.resize(4 * n);
    build(vec, 1, 0, n - 1);

    while (q--) {
        ll s, a, b;
        cin >> s >> a >> b; 
        if (s == 1) update(1, 0, n - 1, a - 1, b);
        else cout << sum(1, 0, n - 1, a - 1, b - 1) << endl;
    }
}