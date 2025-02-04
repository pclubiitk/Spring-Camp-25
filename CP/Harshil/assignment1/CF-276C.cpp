#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() 
{
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int> v1(q);
    vector<int> v2(q);
    for(int i=0;i<q;i++)
    {
        cin>>v1[i]>>v2[i];
    }
    
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    vector<pair<int,int>> count1;
    vector<pair<int,int>> count2;

    count1.push_back(make_pair(v1[0],1));
    count2.push_back(make_pair(v2[0],1));

    for(int i=0;i<q-1;i++)
    {
        if(v1[i]==v1[i+1])
        {
            count1[count1.size()-1].second++;
        }
        else
        {
            count1.push_back(make_pair(v1[i+1],1));
        }
        if(v2[i]==v2[i+1])
        {
            count2[count2.size()-1].second++;
        }
        else
        {
            count2.push_back(make_pair(v2[i+1],1));
        }
    }
    
    // cout<<endl;
    // for(int i=0;i<count1.size();i++)
    // {
    //     cout<<count1[i].first<<" "<<count1[i].second<<endl;
    // }
    // cout<<endl;
    // for(int i=0;i<count2.size();i++)
    // {
    //     cout<<count2[i].first<<" "<<count2[i].second<<endl;
    // }
    // cout<<endl;

    int sum=0;
    int arr[n];
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        if(x<count1.size()&&count1[x].first==i+1)
        {
            sum+=count1[x].second;
            // cout<<sum<<" here 1"<<endl;
            x++;
        }
        if(y<count2.size()&&count2[y].first==i)
        {
            sum-=count2[y].second;
            // cout<<sum<<" here 2"<<endl;
            y++;
        }
        arr[i]=sum;
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    sort(arr,arr+n);
    sort(a,a+n);    

    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=a[i]*arr[i];
    }
    cout<<ans<<endl;
    
}