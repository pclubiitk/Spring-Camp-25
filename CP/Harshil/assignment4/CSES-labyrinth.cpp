#include <bits/stdc++.h>
using namespace std;

int row_move[4] = {-1, 0, 1, 0};
int col_move[4] = {0, 1, 0, -1};
char dir[4] = {'U', 'R', 'D', 'L'};

void bfs(pair<int, int> start, pair<int, int> end, vector<vector<int>> &grid, vector<vector<int>> &distance_map, vector<vector<pair<int, int>>> &parent,int n,int m)
{
    queue<pair<int, int>> q;
    q.push(start);
    grid[start.first][start.second] = 0;
    distance_map[start.first][start.second] = 0;
    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        if (current == end)
        {
            cout << "YES\n";
            cout << distance_map[end.first][end.second] << endl;
        
            vector<char> path;
            pair<int, int> temp = end;
            while (temp != start)
            {
                pair<int, int> prev = parent[temp.first][temp.second];
                for (int i = 0; i < 4; i++)
                {
                    if (prev.first + row_move[i] == temp.first && prev.second + col_move[i] == temp.second)
                    {
                        path.push_back(dir[i]);
                        break;
                    }
                }
                temp = prev;
            }
            reverse(path.begin(), path.end());
            for (char c : path)
                cout << c;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int new_row = current.first + row_move[i];
            int new_col = current.second + col_move[i];

            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && grid[new_row][new_col] == 1)
            {
                q.push({new_row, new_col});
                grid[new_row][new_col] = 0;
                distance_map[new_row][new_col] = distance_map[current.first][current.second] + 1;
                parent[new_row][new_col] = current;
            }
        }
    }

    cout << "NO\n";
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> distance_map(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    pair<int, int> start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char a;
            cin >> a;
            if (a == '#')
                grid[i][j] = 0; 
            else if (a == '.')
                grid[i][j] = 1;
            else if (a == 'A')
            {
                grid[i][j] = 1;
                start = {i, j};
            }
            else if (a == 'B')
            {
                grid[i][j] = 1;
                end = {i, j};
            }
        }
    }

    bfs(start, end, grid, distance_map, parent,n,m);
    return 0;
}
