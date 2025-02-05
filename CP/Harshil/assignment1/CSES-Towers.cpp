#include<bits/stdc++.h>
using namespace std;
#define int long long

int binarySearch(vector<int>& v, int target) 
{
    int low = 0, high = v.size() - 1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (v[mid] <= target) 
        {
            low = mid + 1;
        } 
        else 
        {
            high = mid - 1;
        }
    }
    return low;
}


void solve(int arr[],int n)
{
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int position=binarySearch(v,arr[i]);
        if(position==v.size())
        {
            v.push_back(arr[i]);
        }
        else
        {
            v[position]=arr[i];
        }
    }
    cout<<v.size()<<endl;
}

int32_t main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    solve(arr,n);
}