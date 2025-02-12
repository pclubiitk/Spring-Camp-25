#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

ll query(int l, int r, int cur, int start, int end, vll& tree) {
    if (r < start || l > end) return 0; // Neutral for AND
    if (l <= start && end <= r) return tree[cur];
    ll mid = (start + end) / 2;
    return (query(l, r, 2 * cur + 1, start, mid,tree) + query(l, r, 2 * cur + 2, mid + 1, end,tree));
}

void update(vll& tree, int cur, int pos, ll val, int l, int r){
    if(l==r){
        tree[cur]+=val;
    } else {
        int mid=(l+r)/2;
        if(pos<=mid){
            update(tree,2*cur+1,pos,val,l,mid);
        } else {
            update(tree,2*cur+2,pos,val,mid+1,r);
        }
        tree[cur]=tree[2*cur+1]+tree[2*cur+2];
    }
}
// The tree stores +x at l and -x at r+1 and then for a given position, we require sum[1,k] + a[k] (1 based indexing). (Like prefix sum)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vll a(n);
    rep(i,0,n-1) cin>>a[i];
    vll tree(4*n);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int a,b; ll u;
            cin>>a>>b>>u;
            --a,--b;
            update(tree,0,a,u,0,n-1);
            if(b<=n-2){
                update(tree,0,b+1,-u,0,n-1);
            }
        } else {
            int k;
            cin>>k;
            cout<<query(0,k-1,0,0,n-1,tree)+a[k-1]<<"\n";
        }
    }
    return 0;
}