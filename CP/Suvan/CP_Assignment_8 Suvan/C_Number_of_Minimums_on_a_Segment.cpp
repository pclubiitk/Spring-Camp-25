#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

vector<pair<ll, int> > tree;
vi num;

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = make_pair(num[l], 1);
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * node + 1, l, mid);
    build(2 * node + 2, mid + 1, r);
    auto left = tree[2 * node + 1];
    auto right = tree[2 * node + 2];
    if (left.first < right.first)
        tree[node] = left;
    else if (left.first > right.first)
        tree[node] = right;
    else
        tree[node] = make_pair(left.first, left.second + right.second);
}
 
void update(int node, int l, int r, int index, ll val) {
    if (l == r) {
        tree[node] = make_pair(val, 1);
        return;
    }
    int mid = l + (r - l) / 2;
    if (index <= mid)
        update(2 * node + 1, l, mid, index, val);
    else
        update(2 * node + 2, mid + 1, r, index, val);
    
    auto left = tree[2 * node + 1];
    auto right = tree[2 * node + 2];
    if (left.first < right.first)
        tree[node] = left;
    else if (left.first > right.first)
        tree[node] = right;
    else
        tree[node] = make_pair(left.first, left.second + right.second);
}
 
pair<ll, int> query(int node, int start, int end, int l, int r) {
    if (r < start || l > end)
        return make_pair(LLONG_MAX, 0); 
    if (l <= start && end <= r)
        return tree[node];
    
    int mid = start + (end - start) / 2;
    auto leftRes = query(2 * node + 1, start, mid, l, r);
    auto rightRes = query(2 * node + 2, mid + 1, end, l, r);
    if (leftRes.first < rightRes.first)
        return leftRes;
    else if (leftRes.first > rightRes.first)
        return rightRes;
    else
        return make_pair(leftRes.first, leftRes.second + rightRes.second);
}
 
int main() {
    fast_io();
 
    int test = 1;
    // cin >> test; 
    while (test--) {
        int n, m;
        cin >> n >> m;
        num.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        tree.assign(4 * n, make_pair(LLONG_MAX, 0));
        build(0, 0, n - 1);
        for (int i = 0; i < m; i++) {
            int a;
            cin>>a;
            if(a==1){
                int b,c;
                cin>>b>>c;
                update(0,0,n-1,b,c);
            }
            else{
                int b,c;
                cin>>b>>c;
                pair<ll,int> ans = query(0,0,n-1,b,c-1);
                cout<<ans.first<<" "<<ans.second<<endl;
            }
        }
    }
 
    return 0;
}