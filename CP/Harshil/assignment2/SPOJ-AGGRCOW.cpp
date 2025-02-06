#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);

        int l=1,r=arr[n-1]-arr[0];
        int ans = 0;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            int cows_placed=1;
            int temp_sum=0;
            for(int i=0;i<n-1;i++)
            {
                temp_sum+=(arr[i+1]-arr[i]);
                if(temp_sum>=mid)
                {
                    cows_placed++;
                    temp_sum=0;
                }
            }
            if(cows_placed>=c)
            {
                ans = mid;      
                l=mid+1;     
            }
            else
            {
                r=mid-1;    
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}