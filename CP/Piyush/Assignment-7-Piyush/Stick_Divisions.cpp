#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,n;cin>>x>>n;
    priority_queue<long long,vector<int>,greater<int>> v;
    for(int i=1;i<=n;i++){
        long long y;cin>>y;
        v.push(y);
    }
    long long int sum=0;
    long long int res=0;
    for(int i=1;i<=n-1;i++)
    {
        sum+=v.top();v.pop();sum+=v.top();v.pop();
        res+=sum;
        v.push(sum);
        sum=0;
    }
    cout<<res;

}