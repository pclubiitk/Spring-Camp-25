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
vector<vector<int> > adj(n);
vi number(n,0);
void dfs(int vertex, int par) {
    // Take action on vertex after entering the vertex
    for (int child : adj[vertex]) {
        // Take action on child before entering the child node
        if (child!=par) {
                dfs(child,vertex);
                number[vertex] += number[child] + 1;
        }

        // Take action on child after exiting the child node
    }
    // Take action on vertex after exiting the vertex
}

int main() {
    fast_io();

    int test = 1;
    //cin >> test;
    while(test--) {
        cin>>n;

        adj.assign(n + 1, vector<int>()); 
        number.assign(n + 1, 0); 

        for(int i = 1; i<n; i++){
            int a;
            cin>>a;
            adj[i+1].push_back(a);
            adj[a].push_back(i+1);
        }
        dfs(1,0);
        for(int i = 1; i<=n; i++){
            cout<<number[i]<<" ";
        }
    }

    return 0;
}

