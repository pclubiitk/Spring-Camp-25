#include<bits/stdc++.h>
using namespace std;
void soe(map<long long int,int>& m,long long int n)
{
    long long int size=(1000000LL>n)?n:1000000LL;
    vector<bool> v(size+1,true);
    v[0]=v[1]=false;
    for(long long int i=2;i<=size;i++)
    {
        if(v[i])
        {
            m[i]=0;
            while(!(n%i))
            {
                n=n/i;
                m[i]++;
            }
            for(long long int j=i*i;j<=size;j+=i)
            {
                v[j]=false;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--)
    {
        string s;cin>>s;
        long long int n;cin>>n;
        int l;cin>>l;
        map<long long int,int> factor;
        soe(factor,n);
        int count=0;
        for(auto& i:factor)
        {
            if(count==l) break;
            cout<<s[i.second];
            count++;
        }
        if(count<l)
        {
            for(int i=1;i<=(l-count);i++) cout<<s[0];
        }
        cout<<endl;
    }
}