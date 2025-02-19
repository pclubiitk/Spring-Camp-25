#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f(i,t,n) for(int i = t; i < n;i++)

vector<ll> tree;
int n;

void build(const vector<int>& a, int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        build(a, 2 * node + 1, start, mid);
        build(a, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

void update(int idx, int val, int node, int start, int end) {
    if (start == end) {
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(idx, val, 2 * node + 1, start, mid);
        } else {
            update(idx, val, 2 * node + 2, mid + 1, end);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

void update(int idx, int val) {
    update(idx, val, 0, 0, n - 1);
}

ll query(int l, int r, int node, int start, int end) {
    if (r < start || l > end) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return query(l, r, 2 * node + 1, start, mid) + query(l, r, 2 * node + 2, mid + 1, end);
}

ll query(int l, int r) {
    return query(l, r, 0, 0, n - 1);
}

void solve() {
    int q;
    cin >> n >> q;
    vector<int> arr(n);
    f(i, 0, n) cin >> arr[i];
    
    tree.resize(4 * n);
    build(arr, 0, 0, n - 1);
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            update(k - 1, u);
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            cout << query(a - 1, b - 1) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    ll test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}

