#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vdll vector<vector<ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define inf 1e15
#define MOD 1000000007
// AC after 3 WA
vll parent, sized;
vll expr;
vll ext;

void ms(ll v) {
    parent[v] = v;
    sized[v] = 1;
    expr[v] = 0;
    ext[v] = 0;
}


ll par(ll v) {
    if (parent[v] == v)
        return v;
    ll p = par(parent[v]);
    ext[v] += ext[parent[v]];  //forgor this
    return parent[v] = p;
}

void uni(ll v, ll w) {
    v = par(v);
    w = par(w);
    if (v != w) {
        if (sized[v] < sized[w]) swap(v, w);
        parent[w] = v;
        sized[v] += sized[w];
        ext[w] = expr[v]-expr[w];//was not removing expr[w] here
    }
}

void pts(ll a, ll v) {
    expr[par(a)] += v;
}

ll e(ll a) {
    ll pr = par(a); 
    return (a == pr) ? expr[a] : expr[pr] - ext[a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    sized.resize(n + 1);
    expr.resize(n + 1);
    ext.resize(n + 1);

    for (ll i = 1; i <= n; i++) 
        ms(i);

    while (m--) {
        string s;
        ll a, b;
        cin >> s;
        if(s == "get") {
            cin >> a;
            ll pr= par(a);
            if(a==pr)cout<<expr[a]<<endl;
            else cout<<expr[pr]-ext[a]<<endl;
        }
        else {
            cin >> a >> b;
            if(s == "join") uni(a, b);
            if(s == "add") pts(a, b);
        }
    }
}

