#include<bits/stdc++.h>
using namespace std;
#define int long long

bool compare(const pair<int, int>& a, const pair<int, int>& b) 
{
    return a.first < b.first;
}


int binary_search(const vector<pair<int, int>>& arr, int target, int j) {
    int l = j + 1, r = arr.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid].first == target) {
            return arr[mid].second;
        } else if (arr[mid].first < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

void solve(vector<pair<int,int>> arr,int sum)
{
    sort(arr.begin(),arr.end(),compare);
    for(int i=0;i<arr.size();i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            int target=sum-(arr[i].first)-(arr[j].first);
            // cout<<target<<endl;
            // auto it=lower_bound(arr.begin()+j+1,arr.end(),make_pair(target,0),compare);
            int x =binary_search(arr,target,j);
            // if(it!=arr.end() && it->first==target)
            // {
            //     cout<<arr[i].second<<" "<<arr[j].second<<" "<<it->second<<endl;
            //     return;
            // }
            if(x!=-1)
            {
                cout<<arr[i].second<<" "<<arr[j].second<<" "<<x<<endl;
                return;
            }
            
        }
    }
    cout<<"IMPOSSIBLE\n";
}

int32_t main()
{
    int n;
    int sum=0;
    cin>>n>>sum;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].first;
        arr[i].second=i+1;
    }
    // cout<<sum<<endl;
    solve(arr,sum);
    
}