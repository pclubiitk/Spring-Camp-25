#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())
vi num;
vi tree;
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void build(int index,int l, int r){
    if(l==r){
        tree[index] = num[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*index+1,l,mid);
    build(2*index+2,mid+1,r);
    tree[index] = min(tree[2*index+1],tree[2*index+2]);
}

int query(int l , int r, int node, int start, int end){
    if(r<start || end<l) return INT_MAX;
    if(l<=start && end<=r) return tree[node];
    int mid = (start+end)/2;
    return min(query(l,r,2*node+1,start,mid),query(l,r,2*node+2,mid+1,end));
}

int query(int l, int r, int n){
    return query(l,r,0,0,n-1);
}

int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {
        int n,q;
        cin>>n>>q;
        num.resize(n+1);
        tree.resize(4*n+1);
        for(int i = 0; i<n; i++){
            cin>>num[i];
        }
        build(0,0,n-1);
        for(int i = 0; i<q; i++){
            int a,b;
            cin>>a>>b;
            cout<<query(a-1,b-1,n)<<endl;
        }
        


    }

    return 0;
}