#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
int32_t main()
{
    FAST_IO
    int x,n;
    cin>>x>>n;
    priority_queue<int,vector<int>,greater<int>> pq;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        pq.push(a);
    }
    while(pq.size()>1)
    {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }
    cout<<ans<<"\n";
}