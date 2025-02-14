#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i, t, n) for (ll i = t; i < n; i++)

vector<ll> tree;
ll n, q;

void build(vector<ll> &arr, ll node, ll start, ll end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        ll mid = (start + end) / 2;
        build(arr, 2 * node + 1, start, mid);
        build(arr, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

ll query(ll node, ll start, ll end, ll idx) {
    if (start == end) return tree[node];

    ll mid = (start + end) / 2;
    if (idx <= mid) return query(2 * node + 1, start, mid, idx);
    else return query(2 * node + 2, mid + 1, end, idx);
}

void solve() {
    cin >> n >> q;
    vector<ll> a(n), diff(n + 1, 0);

    f(i, 0, n) cin >> a[i];

    f(i, 0, q) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll l, r, u;
            cin >> l >> r >> u;
            diff[l - 1] += u;
            diff[r] -= u; 
        }
    }

    vector<ll> modified(n);
    modified[0] = a[0] + diff[0];
    f(i, 1, n) {
        diff[i] += diff[i - 1]; 
        modified[i] = a[i] + diff[i];
    }

    tree.resize(4 * n, 0);
    build(modified, 0, 0, n - 1);

    ll num_queries;
    cin >> num_queries;
    f(i, 0, num_queries) {
        ll k;
        cin >> k;
        cout << query(0, 0, n - 1, k - 1) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test = 1;
    // cin>>test;
    while (test--) {
        solve();
    }
    return 0;
}
