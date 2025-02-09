#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
	cin>>n>>m;
	int adj_grid[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			adj_grid[i][j]=0;
		}
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		adj_grid[a-1][b-1]=1;
		adj_grid[b-1][a-1]=1;
	}
	vector<pair<int,pair<int,int>>>visited(n,{0,{0,-2}});
	queue<int>q;
	q.push(0);
	visited[0]={1,{1,-1}};
	while(!q.empty())
	{
		int currentnode=q.front();
		q.pop();
		if(currentnode==n-1)
		{
			goto flag1;
		}
		for(int j=0;j<n;j++)
		{
			if(adj_grid[currentnode][j]==1&&visited[j].first==0)
			{
				q.push(j);
				visited[j].first=1;
				visited[j].second.first=visited[currentnode].second.first+1;
				visited[j].second.second=currentnode;
			}
			else
			{
				continue;
			}
		}
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
	
	flag1:
	cout<<visited[n-1].second.first<<endl;
	vector<int>path;
	path.push_back(n-1);
	while(1)
	{
		if(visited[path[path.size()-1]].second.second==-1)
		{
			break;
		}
		int temp=visited[path[path.size()-1]].second.second;
		path.push_back(temp);
	}
	for(int i=path.size()-1;i>=0;i--)
	{
		cout<<path[i]+1<<" ";
	}
}
