#include <bits/stdc++.h>
using namespace std;


char dir[4] = {'U', 'R', 'D', 'L'};

int bfs(const vector<vector<int>> &grid,vector<vector<int>>&visited,int n,int m, pair<int,int> start)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = 1;

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        int row_move[4] = {-1, 0, 1, 0};
        int col_move[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int new_row = current.first + row_move[i];
            int new_col = current.second + col_move[i];
            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && visited[new_row][new_col] == 0 && grid[new_row][new_col] == 1)
            {
                visited[new_row][new_col] = 1;
                q.push({new_row, new_col});
            }
        }
    }
    return 1;
}


int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 0;
            char a;
            cin >> a;
            if (a == '#')
                grid[i][j] = 0; 
            else if (a == '.')
                grid[i][j] = 1;
        }
    }

    pair<int,int> start;
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            // cout<<i<<" "<<j<<" here 1"<<endl;
            if(grid[i][j]==1 && visited[i][j]==0)
            {
                // cout<<i<<" "<<j<<endl;
                start={i,j};
                count+=bfs(grid,visited,n,m,start);
            }
        }
    }
    cout << count << endl;
    return 0; 
}
    

