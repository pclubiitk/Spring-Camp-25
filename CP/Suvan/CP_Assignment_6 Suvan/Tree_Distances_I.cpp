#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

vector<vector<int> > adj;
vector<int> dis;

void dfs(int vertex, int par = -1) {
    // Take action on vertex after entering the vertex

    for (int child : adj[vertex]) {
        // Take action on child before entering the child node
            if(child == par) continue;
            dis[child] = dis[vertex] + 1;
            dfs(child,vertex);
        
        // Take action on child after exiting the child node
    }
    // Take action on vertex after exiting the vertex
}
int far_node(int n){

    fill(all(dis),0);
    dfs(n);
    int farthest,max_distance = 0;
    for(int i = 0; i<dis.size(); i++){
        if(dis[i]>max_distance){
            max_distance = dis[i];
            farthest = i;
        }
    }
    return farthest;
}

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {
        int n;
        cin>>n;
        adj.resize(n);
        dis.resize(n);

        for(int i = 0; i<n-1; i++){
            int a,b;
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        int max1 = far_node(0);
        int max2 = far_node(max1);

        vi d1(n,0), d2(n,0);

        dis.assign(n,0);
        dfs(max1);
        d1 = dis;

        dis.assign(n,0);
        dfs(max2);
        d2 = dis;

        for(int i = 0; i<n; i++){
            cout<<max(d1[i],d2[i])<<" ";
        }


    }

    return 0;
}