#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vdll vector<vector<ll>>
#define pll pair<ll, ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define inf 1e15
#define MOD 1000000007

 
ll n, q;
vll seg;   
vll diff;  
 

void build(int idx, int l, int r) {
    if(l == r) {
        seg[idx] = diff[l];
    } else {
        int mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }
}
 
void update(int idx, int l, int r, int pos, ll val) {
    if(l == r) {
        seg[idx] += val;
    } else {
        int mid = (l + r) / 2;
        if(pos <= mid)
            update(2 * idx, l, mid, pos, val);
        else
            update(2 * idx + 1, mid + 1, r, pos, val);
        seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
    }
}

ll query(int idx, int l, int r, int ql, int qr) {
    if(ql > r || qr < l)
        return 0;
    if(ql <= l && r <= qr)
        return seg[idx];
    int mid = (l + r) / 2;
    return query(2 * idx, l, mid, ql, qr) + query(2 * idx + 1, mid + 1, r, ql, qr);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> q;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) 
        cin >> v[i];
    
    
    diff.resize(n);
    diff[0] = v[0];
    for (int i = 1; i < n; i++) {
        diff[i] = v[i] - v[i - 1];
    }
 
    seg.assign(4 * n, 0);
    build(1, 0, n - 1);
    

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int a, b;
            ll u;
            cin >> a >> b >> u;
            int idx_a = a - 1; 
            int idx_b = b - 1; 

            update(1, 0, n - 1, idx_a, u);

            if(idx_b + 1 < n)update(1, 0, n - 1, idx_b + 1, -u);
        } else {
            int k;
            cin >> k;
            int idx_k = k - 1; 

            ll ans = query(1, 0, n - 1, 0, idx_k);
            cout << ans << "\n";
        }
    }
}
