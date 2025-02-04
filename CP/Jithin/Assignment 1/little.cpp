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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vi els(n+1);
    vi count(n+1);
    rep(i,1,n) cin>>els[i];
    while(q--){
        int l,r;
        cin>>l>>r;
        ++count[l-1];
        --count[r];
    }
    int cur=0;
    int prev=count[0];
    rep(i,1,n){
        cur+=prev;
        prev=count[i];
        count[i]=cur;
    }
    sort(count.begin()+1,count.end());
    sort(els.begin()+1,els.end());
    ll sum=0;
    rep(i,1,n) sum+=(ll)count[i]*els[i];
    cout<<sum;
    return 0;
}