#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(){
    ll n,target;
    cin>>n>>target;
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i].first;
        v[i].second=i+1;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        ll left=i+1;
        ll right=n-1;
        while(left<right){
            if(v[left].first+v[right].first+v[i].first==target){
                cout<<v[i].second<<" "<<v[left].second<<" "<<v[right].second<<endl;return;
            }
            if(v[left].first+v[right].first+v[i].first>target){
                right--;
            }
            else{
                left++;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";return;
}
int main(){
    ll t;
    t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}