#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
int main()
{
    int n,q;cin>>n>>q;
    adj.resize(n+1);
    vector<int> parent(n+1);
    for(int i=2;i<=n;i++)
    {
        cin>>parent[i];
    }
    parent[1]=0;
    int log=20;
    vector<vector<int>> up(n,vector<int>(log));
    vector<int> dep(n+1);
    dep[1]=0;
    for(int i=2;i<=n;i++)
    {
        dep[i]=dep[parent[i]]+1;
    }
    for(int i=1;i<=n;i++)
    {
        up[i][0]=parent[i];
    }
    for(int j=1;j<log;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(up[i][j-1]!=0)
            {
                up[i][j]=up[up[i][j-1]][j-1];
            }
            else{
                up[i][j]=0;
            }
        }
    }
    while(q--){
        int x,k;cin>>x>>k;
        if(dep[x]<k)
        {
            cout<<"-1"<<endl;
            continue;
        }
        int curr=x;
        for(int j=0;j<log;j++)
        {
            if(k&(1<<j)){
                curr=up[curr][j];
            }
        }
        cout<<curr<<endl;

    }

}
