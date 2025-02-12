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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    ll sum=n%2?-1:1;
    ll cur=1;
    ll sub=n;
    ll curSign=n%2?1:-1;
    while(sub!=2){
        cur*=sub;
        cur%=MOD;
        sum+=curSign*cur;
        sum%=MOD;
        curSign*=-1;
        sub-=1;
    }
    cout<<(sum+MOD)%MOD;
    return 0;
}