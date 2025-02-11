#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}


int m, n;
vector<string> matrix;
vector<vector<bool> > visited;

void dfs(int i, int j) {
    if (i < 0 || j < 0 || i >= m || j >= n) return;
    if(matrix[i][j] == 'B') return;
    if (matrix[i][j] != '.' || visited[i][j]) return;

    visited[i][j] = true;

    dfs(i - 1, j); 
    dfs(i + 1, j); 
    dfs(i, j - 1); 
    dfs(i, j + 1);
}


int main() {
    fast_io();

    int test = 1;
    //cin >> test;
    while(test--) {
        cin>>m>>n;
        matrix.resize(m);

        for(int i = 0; i<m; i++){
            cin>>matrix[i];
        }

        vector<char> path;
        visited.assign(m,vector<bool>(n,false));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if((matrix[i][j] == '.') || (matrix[i][j] == 'A' ) && visited[i][j]!=true){
                    path.push_back(matrix[i][j]);

                    dfs(i,j);
                }
            }
        }

        cout<<path.size()<<endl;
        for(int i = 0; i<path.size(); i++){
            cout<<path[i]<<" ";
        }
    }

    return 0;
}