#include<bits/stdc++.h>
using namespace std;

string s1="cut";
string s2="ask";

int get_parent(int a,vector<int>& parent)
{
    if(parent[a]==a) return a;
    return get_parent(parent[a],parent);
}

void check(int a,int b,vector<int>& parent)
{
    if(get_parent(a,parent)==get_parent(b,parent))
    {
        cout<<"yes\n";
    }
    else
    {
        cout<<"no\n";
    }
}

void make_connection(int a,int b,vector<int>& parent,vector<int>& size)

{
    int parent_a=get_parent(a,parent);
    int parent_b=get_parent(b,parent);
    if(parent_a!=parent_b)
    {
        if(size[parent_b]<size[parent_a]) swap(parent_a,parent_b);
        parent[parent_a]=parent_b;
        size[parent_b]+=size[parent_a];
    }
}   

void remove_connection(int a,int b,vector<int>& parent,vector<int>& size)
{
    int parent_a=get_parent(a,parent);
    int parent_b=get_parent(b,parent);
    if(parent_a!=parent_b)
    {
        return;
    }
    parent[a]=a;
    parent[b]=b;
    size[a]=1;
    size[b]=1;
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> parent(n+1);
    vector<int> size(n+1);

    for(int i=1;i<n+1;i++)
    {
        parent[i]=i;
        size[i]=1;
    }

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        make_connection(a,b,parent,size);
    }

    for(int i=0;i<k;i++)
    {
        string s;
        int a,b;
        cin>>s>>a>>b;
        if(s==s1)
        {
            remove_connection(a,b,parent,size);
        }
        else
        {
            check(a,b,parent);
        }
    }
}