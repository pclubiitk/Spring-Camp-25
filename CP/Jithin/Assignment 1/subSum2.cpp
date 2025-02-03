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
    int n;
    ll x;
    cin>>n>>x;
    map<long long, int> pref; // {sum,no of same sum}
    pref[0]=1;
    ll sum=0;
    ll count=0;
    rep(i,0,n-1){
        int y;
        cin>>y;
        sum+=y;
        count+=pref[sum-x];
        ++pref[sum];
    }
    cout<<count;
    return 0;
}