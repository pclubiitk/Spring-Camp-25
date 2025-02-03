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

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi a(n);
    vi leftPref(n);
    int cur=0;
    rep(i,0,n-1){
        cin>>a[i];
        cur=gcd(cur,a[i]);
        leftPref[i]=cur;
    }
    cur=0;
    vi rightPref(n);
    for(int i=n-1;i>=0;--i){
        cur=gcd(cur,a[i]);
        rightPref[i]=cur;
    }
    int curMax=max(leftPref[n-2],rightPref[1]);
    rep(i,1,n-2){
        curMax=max(curMax,gcd(leftPref[i-1],rightPref[i+1]));
    }
    cout<<curMax;
    return 0;
}