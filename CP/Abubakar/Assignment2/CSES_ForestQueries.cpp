#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vdc vector<vector<char>>
#define vdll vector<vector<ll>>
#define vll vector<ll>
#define vc vector<char>
#define vpll vector<pair<ll>>
#define s second
#define f first
#define ld long double
#define loop(i,n) for(int i=0;i<n;i++)
#define lop(i,n) for(int i=1;i<=n;i++)
 
int main()
{
    ll n,q;
    cin>>n>>q;
    vdc v(n,vc(n));
    vdll ps(n+1,vll(n+1,0));
    
    loop(i,n)
    {
        loop(j,n)
        {
            cin>>v[i][j];
        }
    }
    
 
    loop(i,n)
    {
        loop(j,n)
        {
            ps[i+1][j+1] = ps[i+1][j] + ps[i][j+1] - ps[i][j] + (v[i][j] == '*');
        }
    }
    
 
    while(q--)
    {
        ll y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        ll ty2=y2;
        ll ty1=y1;
        ll tx1=x1;
        ll tx2=x2;
        y2=max(ty1,ty2);
        x2= max(tx1,tx2);
        y1=min(ty2,ty1);
        x1=min(tx1,tx2);
        ll res = ps[y2][x2] - ps[y2][x1-1] - ps[y1-1][x2] + ps[y1-1][x1-1];
        cout<<res<<endl;
    }
}
