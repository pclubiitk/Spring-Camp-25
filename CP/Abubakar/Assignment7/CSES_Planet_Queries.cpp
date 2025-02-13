#include <bits/stdc++.h>
using namespace std;
#define ll int
#define vpll vector<pair<ll, ll>>
#define vdll vector<vector<ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define loop(i, n) for(int i = 0; i < n; i++)
#define one(i, n) for(int i = 1; i <= n; i++)
#define ss second
#define all(v) v.begin(), v.end()
#define MOD 1000000007
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, q;
    cin >> n >> q;
    vll v(n+1);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    
    ll maxc = 30;
    vdll anc(n+1, vll(maxc, 0));
    
    for (int i = 1; i <= n; i++){
        anc[i][0] = v[i];
    }
    
    for (int j = 1; j < maxc; j++){
        for (int i = 1; i <= n; i++){
            if (anc[i][j-1] != 0) {
                anc[i][j] = anc[anc[i][j-1]][j-1];
            }
        }
    }
    
    while(q--){
        ll x, k;
        cin >> x >> k;
        for (int i = 0; i < maxc; i++){
            if(k & (1 << i)) x = anc[x][i];
        }
        cout << x << "\n";
    }
}