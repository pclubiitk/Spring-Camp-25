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
const ll N=1e5+2;
vll vis(N,0);
vll adj[N];
ll gr=0;
void dfs(ll i)
{
    vis[i]=1;
    for(auto x: adj[i])
    {
        if(!vis[x])dfs(x);
       
    }

}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>p;
    while(m--)
    {
        ll l,r;
        cin>>l>>r;
        adj[l].pb(r);
        adj[r].pb(l);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])p.pb(i),dfs(i);
    }

    ll th= p.size()-1;
    if(th==0) {cout<<0<<endl;return 0;}
    cout<<th<<endl;
    for(int i=0;i<th;i++)
    {
        cout<<p[i]<<" "<<p[i+1]<<endl;
    }
}