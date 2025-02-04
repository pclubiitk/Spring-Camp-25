#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }

    long long int l=*max_element(arr, arr + n),r=sum;
    while(l<r)
    {
        long long int mid=l+(r-l)/2;
        long long int subarrays=0;
        long long int temp_sum=0;
        for(int i=0;i<n;i++)
        {
            if(temp_sum+arr[i]>mid)
            {
                subarrays++;
                temp_sum=0;
            }
            
            temp_sum+=arr[i];
        }
        subarrays++;
        // cout<<mid<<" "<<subarrays<<endl;
        if(subarrays<=k)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<l<<endl;
}