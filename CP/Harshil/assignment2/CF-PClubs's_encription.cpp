#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int prime(int k)
{
    if(k==1)
    {
        return 0;
    }
    if(k==2)
    {
        return 1;
    }
    if(k%2==1)
    {
        for(int i=3;i*i<=k;i+=2)
        {
            if(k%i==0)
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int32_t main()
{
    int t;
    cin>>t;
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    while(t--)
    {
        string s;
        int n,l;
        cin>>s>>n>>l;
 
        int arr2[l];
        for(int i=0;i<l;i++)
        {
            arr2[i]=0;
        }
        if(arr.size()<l)
        {
            int count=arr.size();
            int k=arr[arr.size()-1]+2;
            while(count<l)
            {
                if(prime(k)==1)
                {
                    arr.push_back(k);
                    count++;
                }
                k+=2;
            }
        }
        for(int i=0;i<l;i++)
        {
            while(n%arr[i]==0)
            {
                arr2[i]++;
                n=(n/arr[i]);
            }
        }
        for(int i=0;i<l;i++)
        {
            cout<<s[arr2[i]];
        }
        cout<<"\n";
    }
}