#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define vi vector<ll>
#define pr pair<ll,ll>
#define vii vector<pair<ll,ll>
void solve(){
    int n;
    cin>>n;
    vi arr(n+1,10000000000000);
    for(int i=1;i<min(10,n+1);i++){
        arr[i]=1;
    }
    for(int i=10;i<=n;i++){
        int z=i;
        while(z>0){
            int y=z%10;
            z=z/10;
            arr[i]=min(arr[i],1+arr[i-y]);
        }
    }
    cout<<arr[n];
}
int main(){
    int t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
