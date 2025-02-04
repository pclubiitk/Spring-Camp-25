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

// phi(MOD)= MOD-1; phi(MOD-1)=500000002

ll power(ll x, ll y, ll mod){
    ll res=1;
    while(y>0){
        if(y&1) res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}

ll exp(ll b, ll c){
    c %= 500000002;
    return power(b,c,MOD-1);
}

ll base(ll a, ll b){
    return power(a,b,MOD);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    while(n--){
        ll a,b,c;
        cin>>a>>b>>c;
        cout<<base(a,exp(b,c))<<"\n";
    }
    return 0;
}