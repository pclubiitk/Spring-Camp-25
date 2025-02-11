#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
vi depth;
vector<vector<int> > graph;
void dfs(int vertex,int par = -1) {
    // Take action on vertex after entering the vertex

    for (int child : graph[vertex]) {
        // Take action on child before entering the child node
        if(child==par) continue;
        depth[child] = depth[vertex]+1;
        dfs(child,vertex);
        // Take action on child after exiting the child node
    }
    // Take action on vertex after exiting the vertex
}


int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {
        int n;
        cin>>n;
        depth.resize(n,0);
        graph.resize(n);
        for(int i = 0; i<n-1; i++){
            int a,b;
            cin>>a>>b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }
        dfs(0);
        int max_depth = -1;
        int max_node;
        for(int i = 0; i<n; i++){
            if(max_depth<depth[i]){
                max_depth = depth[i];
                max_node = i;
            }
            depth[i] = 0;
        }
        dfs(max_node);
        max_depth = -1;
        for(int i =0; i<n; i++){
            max_depth = max(max_depth,depth[i]);
        }

        cout<<max_depth<<endl;
    }

    return 0;
}