
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vdll vector<vector<ll>>
#define pll pair<ll, ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define inf 1e15
#define MOD 1000000007
const int MAXN = 300000 + 5;
ll n;

vector<ll> parent, sized;
vector<bool> alp;
vector<ll> r;

void ms(ll x) {
    parent[x] = x;
    sized[x] = 1;
    r[x]=x;
}


ll par(ll x) {
    return parent[x] == x ? x : parent[x] = par(parent[x]);
}

void uni(ll x, ll y) {
    x = par(x), y = par(y);
    if (x != y) {
        if (sized[x] < sized[y]) swap(x, y);
        parent[y] = x;
        sized[x] += sized[y];
    }
}

ll lside(ll x) {
    return (x == 1 ? n : x - 1);
}
ll rside(ll x) {
    return (x == n ? 1 : x + 1);
}

int main(){
     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    
    parent.resize(n + 1);
    sized.resize(n + 1);
    alp.assign(n + 1, false);
    r.resize(n + 1);
    
    for (ll i = 1; i <= n; i++)ms(i);
    for (ll i = 1; i <= n; i++){
        ll x;
        cin >> x;
        ll rep = par(x);
        ll free = r[rep];
      
        cout << free << " ";
        alp[free] = true;
        ll right = rside(free);
        if (alp[right]) {
            uni(free, right);
            r[par(free)] = r[right];
        } else {

            r[par(free)] = right;
        }
    
        ll left = lside(free);
        if (alp[left]) {

            uni(left, free);
            r[par(free)] = r[free];
        }
    }
}
