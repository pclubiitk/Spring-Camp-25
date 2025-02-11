#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr.push_back({b,a});
    }
    sort(arr.begin(),arr.end());
    multiset<int> s;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(s.size()<k)
        {
            s.insert(arr[i].first);
            // cout<<arr[i].first<<endl;
            count++;
        }
        else
        {
            if(*s.begin()<=arr[i].second)
            {
                s.erase(s.begin());
                s.insert(arr[i].first);
                // cout<<arr[i].first<<endl;
                count++;
            }
        }
    }
    cout<<count<<endl;
}