#include<bits/stdc++.h>
using namespace std;

// string s1="union";
// string s2="get";

int get_parent(int a,vector<int>& parent)
{
    if(parent[a]==a) return a;
    return parent[a]=get_parent(parent[a],parent);
}

// void check(int a,int b,vector<int>& parent)
// {
//     if(get_parent(a,parent)==get_parent(b,parent))
//     {
//         cout<<"yes\n";
//     }
//     else
//     {
//         cout<<"no\n";
//     }
// }

void make_connection(int a,int b,vector<int>& parent,vector<int>& size,int& count,int& max_size)

{
    int parent_a=get_parent(a,parent);
    int parent_b=get_parent(b,parent);
    if(parent_a!=parent_b)
    {
        if(size[parent_b]<size[parent_a]) swap(parent_a,parent_b);
        parent[parent_a]=parent_b;
        size[parent_b]+=size[parent_a];
        count--;
        max_size=max(max_size,size[parent_b]);
    }
}   

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> parent(n+1);
    vector<int> size(n+1);
    int count=n;
    int max_size=1;
    for(int i=1;i<n+1;i++)
    {
        parent[i]=i;
        size[i]=1;
    }

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        make_connection(a,b,parent,size,count,max_size);
        cout<<count<<" "<<max_size<<"\n";
    }
}