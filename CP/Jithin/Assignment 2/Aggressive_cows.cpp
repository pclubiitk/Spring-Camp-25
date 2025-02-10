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

bool isValid(int n, vi& stalls,int c,int dist){
    int cowAssigned=1;
    int prev=stalls[0];
    while(cowAssigned<c){
        auto it=lower_bound(stalls.begin(),stalls.end(),prev+dist);
        if(it != stalls.end()){
            prev=*it;
            ++cowAssigned;
        } else return false;
    }
    return true;
}

void solve(){
    int n,c;
    cin>>n>>c;
    vi stalls(n);
    rep(i,0,n-1) cin>>stalls[i];
    sort(stalls.begin(),stalls.end());
    int l=1;
    int r=1e9;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        bool val=isValid(n,stalls,c,mid);
        if(val){
            ans=mid;
            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<"\n";
    }
    return 0;
}