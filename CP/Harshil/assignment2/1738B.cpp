#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(k==1)
        {
            cin>>n;
            cout<<"yes"<<endl;
            continue;
        }
        int arr[k-1];
        int temp,prev_temp;
        cin>>temp;
        prev_temp=temp;
        for(int i=0;i<k-1;i++)
        {
            int new_temp;
            cin>>new_temp;
            arr[i]=new_temp-prev_temp;
            prev_temp=new_temp;
        }
        // cout<<temp<<endl;
        // for(int i=0;i<k-1;i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        if((n-k)!=0&&(ceil((float)temp/(n-k))>arr[0]))
        {
            cout<<"no"<<endl;
            continue;
        }
        else if((n-k)==0&&temp>arr[0])
        {
            cout<<"no"<<endl;
            continue;
        }
        for(int i=0;i<k-2;i++)
        {
            if(arr[i]>arr[i+1])
            {
                cout<<"no"<<endl;
                continue;
            }
        }
        cout<<"yes"<<endl;
    }
}