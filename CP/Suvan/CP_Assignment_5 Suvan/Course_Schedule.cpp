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
int n;
vector<vector<int> > adj;
vector<bool> visited;
vector<bool> pathvisited;
stack<int> temp;
int flag =  0;
void dfs(int vertex) {
    // Take action on vertex after entering the vertex
    visited[vertex] = true;
    pathvisited[vertex] = true;
    for (int child : adj[vertex]) {
        // Take action on child before entering the child node
        if (pathvisited[child] == true){
            flag = 1;
            break;
        }
        else if (!visited[child]) {
            dfs(child);
        }
        // Take action on child after exiting the child node
    }
    if(flag) return;
    pathvisited[vertex] = false;
    temp.push(vertex);
    // Take action on vertex after exiting the vertex 
}

int main() {
    fast_io();

    int test = 1;
   

    //cin >> test;
    while(test--) {
        int m;
        cin>>n>>m;
        adj.assign(n + 1, vector<int>()); 
        visited.assign(n + 1, false);
        pathvisited.assign(n+1, false);
        for(int i = 0; i<m; i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
    }
    for(int i =1; i<=n; i++){
        if(!visited[i]) dfs(i);
    }
    vi ans;
    if(flag){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    while(!temp.empty()){
        ans.push_back(temp.top());
        temp.pop();
    }

    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
    