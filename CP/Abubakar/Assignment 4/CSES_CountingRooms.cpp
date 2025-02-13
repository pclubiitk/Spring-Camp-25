#include <bits/stdc++.h>
#define ll long long
#define vpll vector<pair<ll,ll>>
#define vll vector<ll>
#define vdll vector<vector<ll>>
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f first
#define s second
#define msi multiset<ll>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
ll n,m;
vdll vis(1002,vll(1002,0));
vpll p={{1,0},{-1,0},{0,1},{0,-1}};
vector<string>grid(1002);
void dfs(ll x,ll y)
{
    vis[x][y]=1;
    for(auto z:p)
    {

        ll xd= x+z.f;
        ll yd= y+z.s;
        bool alp=false;
        if(xd<0||yd<0||xd>=n||yd>=m)alp=true;
        if(grid[xd][yd]=='#')alp=true;
        if(!alp && !vis[xd][yd])
        {
            dfs(xd,yd);
        }
    }
}
int main()
{
    ll ct=0;
    cin>>n>>m;
    for(auto &x:grid)cin>>x;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='.'&&!vis[i][j])//like all are marked in one go(which are in one go so they arent visited again
            {
                dfs(i,j);
                ct++;
            }
        }
    }
    cout<<ct<<endl;



}