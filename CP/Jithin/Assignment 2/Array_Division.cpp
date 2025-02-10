#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

bool isPos(vector<ll>& a,int n, int k, ll sum){
    int partitions=0;
    int curLeft=0;
    int curRight=1;
    while(curRight<=n && partitions<=k+1){
        if(a[curRight]-a[curLeft]>sum){
            ++partitions;
            curLeft=curRight-1;
        } else {
            ++curRight;
        }
    }
    if(curRight>=n+1) ++partitions;
    return partitions<=k;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<ll> a(n+1);
    rep(i,1,n){
        ll x;
        cin>>x;
        a[i]=a[i-1]+x;
    }
    ll left=1; ll right=a[n];
    ll ans=0;
    while(left<=right){
        ll mid=(left+right)/2;
        bool possible=isPos(a,n,k,mid);
        if(possible){
            ans=mid;
            right=mid-1;
        } else {
            left=mid+1;
        }
    }
    cout<<ans;
    return 0;
}