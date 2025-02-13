#include <bits/stdc++.h>
using namespace std;

string string1="ask";
string string2="cut";
vector<int>parent;

void make_set(int v,vector<int>& size) 
{
    parent.push_back(v);
    size.push_back(1);
}

int find_set(int v) 
{
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_sets(int a, int b,vector<int>& size) 
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<set<int>> adj(n+1);
    vector<int> size;
    parent.push_back(0);
    size.push_back(0);
    for(int i=0;i<n;i++)
    {
        make_set(i+1,size);
    }
    
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        union_sets(a,b,size);
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<find_set(i)<<" ";
    }
    for(int i=0;i<k;i++)
    {
        string s;
        int a,b;
        cin>>s>>a>>b;

        if(s==string1)
        {
            if(find_set(a)==find_set(b))
            {
                cout<<"Yes\n";
            }
            else
            {
                cout<<"No\n";
            }
        }
        else
        {
            int flag=0;
            adj[a].erase(b);
            adj[b].erase(a);
            for(auto j:adj[a])
            {
                if(find_set(j)==find_set(b))
                {
                    flag=1;
                }
            }
            if(flag)
            {
                continue;
            }
            else
            {
                parent[a]=a;
                parent[b]=b;
                for(int i=1;i<=n;i++)
                {
                    cout<<find_set(i)<<" ";
                }
            }
            
            
        }

    }
    
}