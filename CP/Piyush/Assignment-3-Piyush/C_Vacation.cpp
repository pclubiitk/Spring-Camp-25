#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<vector<long long>> v(n, vector<long long>(3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++) cin>>v[i][j];
    }

    for(int i=1;i<n;i++)
    {
        v[i][0]+=max(v[i-1][1],v[i-1][2]);
        v[i][1]+=max(v[i-1][0],v[i-1][2]);
        v[i][2]+=max(v[i-1][0],v[i-1][1]);
    }
    cout<<max(v[n-1][0],max(v[n-1][1],v[n-1][2]));


}