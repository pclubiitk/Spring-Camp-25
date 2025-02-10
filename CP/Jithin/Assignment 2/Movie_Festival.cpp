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

vector<pi>::iterator finder(vector<pi>::iterator beg, vector<pi>::iterator end, int free){
    while(beg!=end){
        pi el=*beg;
        if(el.S>=free) return beg;
        beg++;
    }
    return end;
}

void solve(){
    int n;
    cin>>n;
    vector<pi> a(n);
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        a[i]={y,x};
    }
    sort(a.begin(),a.end());
    int count=1;
    int free=a[0].F;
    int last=0;
    while(true && last!=n-1){
        auto it=finder(a.begin()+last+1,a.end(),free);
        if(it!=a.end()){
            last=it-a.begin();
            free=a[last].F;
            ++count;
        } else {
            break;
        }
    }
    cout<<count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}