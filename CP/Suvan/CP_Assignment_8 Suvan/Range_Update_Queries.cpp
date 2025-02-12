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

vi num;
vector<ll> tree;
vector<ll> lazy;

void build(int index, int l, int r){
    if(l==r){
        tree[index] = num[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*index+1,l,mid);
    build(2*index+2,mid+1,r);
    tree[index] = tree[2*index+1] + tree[2*index+2];
}
void traverse (int index, int l, int r){
    if(lazy[index]!=0){
        tree[index] += lazy[index];
        if(l != r){
            lazy[2*index+1] += lazy[index]; // reason
            lazy[2*index+2] += lazy[index]; // reason??
        }
        lazy[index] = 0;
    }
}

void update(int node, int start, int end, int l,int r, ll val){
    traverse(node,start,end);

    if(start > r || end < l) return;
    if(start >=l && end <= r){
        tree[node] += val;
        if(start!=end){
            lazy[2*node+1] += val; // reason for this and next step??
            lazy[2*node+2] += val; // reason??
        }
        return;       
    }
    int mid = (start+end)/2;
    update(2*node+1,start,mid,l,r,val);
    update(2*node+2,mid+1,end,l,r,val);
    tree[node] = tree[2*node+1] + tree[2*node+2];
}

long long query_point(int node, int start, int end, int index){
    traverse(node,start,end);
    if(start ==  end) return tree[node];

    int mid = (start+end)/2;
    if(index<=mid) return query_point(2*node+1,start,mid,index);
    else return query_point(2*node+2,mid+1,end,index);
}

int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {
        int n,q;
        cin>>n>>q;
        num.resize(n);
        tree.assign(4*n,0);
        lazy.assign(4*n,0);

        for(int i = 0; i<n; i++){
            cin>>num[i];
        }
        build(0,0,n-1);
        for(int i = 0; i<q; i++){
            int a;
            cin>>a;
            if(a==2){
                int b;
                cin>>b;
                cout<<query_point(0,0,n-1,b-1)<<endl;
            }
            if(a==1){
                int b,c;
                long long d;
                cin>>b>>c>>d;
                update(0,0,n-1,b-1,c-1,d);
            }
        }
    }

    return 0;
}


