#include<bits/stdc++.h>
using namespace std;
bool place(vector<int>& v,int dist,int c){
    int curr=v[0];
    int cow=c-1;
    for(int i=1;i<v.size()-1;i++)
    {
        if((v[i]-curr)>=dist)
        {
            curr=v[i];
            cow--;
        }
        if(cow==0) break;
    }
    return cow==0;

}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,c;cin>>n>>c;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        int lo=0,hi=v[n-1],mid;
        while(lo<hi)
        {
            mid=lo+(hi-lo)/2;
            if(place(v,mid,c)) lo=mid;
            else hi=mid-1;
        }
        cout<<lo<<endl;
    }
}