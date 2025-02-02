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
    cin>>n;
    map<long long, int> pref; // {rem,no of same rem}
    pref[0]=1;
    ll sum=0;
    ll count=0;
    rep(i,0,n-1){
        int y;
        cin>>y;
        sum=(sum+(y%n)+n)%n; // Add n to avoid negative remainder
        count+=pref[sum];
        ++pref[sum];
    }
    cout<<count;
    return 0;
}