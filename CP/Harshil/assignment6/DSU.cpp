#include<bits/stdc++.h>
using namespace std;

string s1="union";
string s2="get";

int get_parent(int a,vector<int>& parent)
{
    if(parent[a]==a) return a;
    return parent[a]=get_parent(parent[a],parent);
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

void make_connection(int a,int b,vector<int>& parent)
{
    int parent_a=get_parent(a,parent);
    int parent_b=get_parent(b,parent);
    if(parent_a!=parent_b)
    {
        if(parent_a<parent_b)
        {
            parent[parent_b]=parent_a;
        }
        else
        {
            parent[parent_a]=parent_b;
        }
    }
}



int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> parent(n+1);
    // vector<int> size(n+1);

    for(int i=1;i<n+1;i++)
    {
        parent[i]=i;
        // size[i]=1;
    }

    for(int i=0;i<m;i++)
    {
        string s;
        int a,b;
        cin>>s>>a>>b;
        if(s==s2)
        {
            check(a,b,parent);
        }
        else
        {
            make_connection(a,b,parent);
        }
    }
}