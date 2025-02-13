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

vector<ll> tree;
vector<ll> lazy;
vector<ll> num;

void build(int node, int start, int end){
    if(start == end){
        tree[node] = num[node];
        return;
    }
    int mid = (start+end)/2;
    build(2*node+1,start,mid);
    build(2*node+2,mid+1,end);

    tree[node] = tree[2*node + 1] + tree[2*node + 2];
}

void traverse(int index, int l, int r){
    if(lazy[index]!=0){
        tree[index] += lazy[index];
        if(l!=r){
            lazy[2*index+1] += lazy[index];
            lazy[2*index+2] += lazy[index];
        }
        lazy[index] = 0;
    } 
}



void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {
        int n;
        cin>>n;
        tree.assign(n,0);
        lazy.assign(n,0);
        for(int i = 0; i<n; i++){
            cin>>num[i];
        }
        int q;
        cin>>q;
        for(int i =0; i<q; i++){
            int a;
            cin>>a;
            if(a==1){

            }
            if(a==2){

            }

        }
    }

    return 0;
}