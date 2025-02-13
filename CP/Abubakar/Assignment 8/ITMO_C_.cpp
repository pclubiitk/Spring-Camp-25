// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pll>
#define vdll vector<vector<ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define inf 1e15
#define MOD 1000000007
ll n, m;
vll v;
vpll seg;


pll minq(pll& left, pll& right) {
    if (left.ff < right.ff)return left;
    if (left.ff > right.ff)return right;

    return { left.ff, left.ss + right.ss };
}
void build(ll idx, ll l, ll r) {
    if (l == r) {
        seg[idx] = { v[l], 1 };
    }
    else {
        ll mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);
        seg[idx] = minq(seg[2 * idx], seg[2 * idx + 1]);
    }
}

void update(ll idx, ll l, ll r, ll pos, ll val) {
    if (l == r) {
        seg[idx] = { val, 1 };
    }
    else {
        ll mid = (l + r) / 2;
        if (pos <= mid) update(2 * idx, l, mid, pos, val);
        else update(2 * idx + 1, mid + 1, r, pos, val);
        seg[idx] = minq(seg[2 * idx], seg[2 * idx + 1]);
    }
}


pll query(ll idx, ll l, ll r, ll ql, ll qr) {
    if (qr < l || ql > r)return { LLONG_MAX, 0 };

    if (ql <= l && r <= qr)return seg[idx];
    ll mid = (l + r) / 2;
    auto ans_l = query(2 * idx, l, mid, ql, qr);
    auto ans_r = query(2 * idx + 1, mid + 1, r, ql, qr);
    return minq(ans_l, ans_r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    v.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    seg.resize(4 * n);
    build(1, 0, n - 1);

    while (m--) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll i;
            ll v;
            cin >> i >> v;
            update(1, 0, n - 1, i, v);
        }
        if (op == 2) {
            ll l, r;
            cin >> l >> r;
            auto ans = query(1, 0, n - 1, l, r - 1);
            cout << ans.ff << " " << ans.ss << '\n';
        }
    }
}
