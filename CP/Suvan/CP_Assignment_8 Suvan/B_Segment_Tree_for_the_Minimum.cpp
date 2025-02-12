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
vector<long long> tree;
vi num;

void build(int node, int l, int r){
    if(l==r){
        tree[node] = num[l];
        return;
    }
    int mid = l+(r-l)/2;
    build(2*node+1,l,mid);
    build(2*node+2,mid+1,r);
    tree[node] = min(tree[2*node+1],tree[2*node+2]);
}

void update(int node,int l, int r, int index, ll val){
    if(l==r){
        tree[node] = val;
        return;
    }
    int mid = l+ (r-l)/2;
    if(index<=mid) update(2*node+1,l,mid,index,val);
    else update(2*node+2,mid+1,r,index,val);

    tree[node] = min(tree[2*node+1],tree[2*node+2]);
}

long long query(int node,int start, int end,int l, int r){
    if(r<start || l>end) return LLONG_MAX;
    if(l<=start && r>=end) return tree[node];

    int mid = start+(end-start)/2;
    return min(query(2*node+1,start,mid,l,r),query(2*node+2,mid+1,end,l,r));
}
int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {
        int n,m;
        cin>>n>>m;
        tree.assign(4*n,LLONG_MAX);
        num.resize(n);
        for(int i = 0; i<n; i++){
            cin>>num[i];
        }
        build(0,0,n-1);
        for(int i = 0; i<m; i++){
            int a;
            cin>>a;
            if(a==2){
                int c,b;
                cin>>c>>b;
                cout<<query(0,0,n-1,c,b-1)<<endl;
            }
            else{
                int c,b;
                cin>>c>>b;
                update(0,0,n-1,c,b);
            }
        }
    }

    return 0;
}

