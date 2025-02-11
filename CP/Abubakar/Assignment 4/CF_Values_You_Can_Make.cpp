#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define vdll vector<vector<ll>>
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define inf (ll)1e12+5

const ll N = 1000010;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<vector<bool>> dp(k+1, vector<bool>(k+1, false));
    dp[0][0] = true; 
    for (ll c : v) {
        for (ll j = k; j >= c; j--) {

            for (ll x = k; x >= 0; x--) {

                if(j - c >= 0 && dp[j-c][x])dp[j][x] = true;
                if(j - c >= 0 &&  x - c >= 0 && dp[j-c][x-c]) dp[j][x] = true;
            }
        }
    }
    

    vector<ll> ans;
    for (ll x = 0; x <= k; x++){
        if(dp[k][x])
            ans.push_back(x);
    }
    
    cout << ans.size() << endl;
    for (ll x : ans)
        cout << x << " ";
    cout << endl;
}
