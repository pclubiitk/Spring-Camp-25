#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vpll vector<pll>
#define pb push_back
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
vll parent;
vll sized;

void ms(ll v) {
    parent[v] = v;
    sized[v] = 1;
}

ll par(ll v) {
    if (parent[v] == v) return v;
    return parent[v] = par(parent[v]); 
}

void uni(ll v, ll w) {
    if(v==0||w==0)return;
    v = par(v), w = par(w);
    if (v != w) {
        if (sized[v] < sized[w]) swap(v, w);
        parent[w] = v;
        sized[v] += sized[w]; 
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    
    parent.resize(n + 1);
    sized.resize(n + 1);
    
    for (ll i = 1; i <= n; i++) ms(i);


    while (m--) {
        ll a; ll temp=0;
        cin>>a;
        while(a--)
        {
            ll x;
            cin>>x;
            uni(temp,x);
            temp=x;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        ll res= sized[par(i)];
        cout<<res<<" ";
    }
    cout<<endl;

}
