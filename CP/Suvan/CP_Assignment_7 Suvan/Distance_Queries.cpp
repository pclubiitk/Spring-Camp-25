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

vector<vi> adj;
vi depth;
int mat[200005][20];

void binary_lifting(int vertex, int par){
    mat[vertex][0] = par;
    for(int i = 1; i<20; i++){
        if(mat[vertex][i-1] == -1) mat[vertex][i] = -1;
        else{
            mat[vertex][i] = mat[mat[vertex][i-1]][i-1];
        }
    }
}

void dfs(int vertex, int par = -1) {
    // Take action on vertex after entering the vertex
    for (int child : adj[vertex]) {
        // Take action on child before entering the child node
        if(child == par) continue;
        depth[child] = depth[vertex] + 1;
        binary_lifting(child,vertex);  
        dfs(child,vertex);
        // Take action on child after exiting the child node
    }
    // Take action on vertex after exiting the vertex
}
int move(int a, int k){
    if(k==0 || a == -1) return a;
    for(int i = 19; i>=0; i--){
        if(k>= (1<<i)){
            if (mat[a][i] == -1) return -1;
            return move(mat[a][i],k-(1<<i));
        }
    }
    return -1;
}

int answer(int a, int b){
    if(depth[b]<depth[a]) swap(a,b);
    b = move(b,depth[b]-depth[a]);
    if (a == b) return a+1;

    for (int i = 19; i >= 0; i--) {
    if (mat[a][i] != mat[b][i]) {
        a = mat[a][i];
        b = mat[b][i];
        }
    }   
    return mat[a][0]+1; 

}



int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {
        int n,q;
        cin>>n>>q;

        adj.resize(n);
        depth.assign(n,-1);
        memset(mat, -1, sizeof(mat));

        for(int i = 0; i<n-1; i++){
            int a,b;
            cin>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }

        depth[0] = 0; 
        binary_lifting(0, -1);
        dfs(0, -1);

        for(int i = 0; i<q; i++){
            int a,b;
            cin>>a>>b;
            int c = answer(a-1,b-1);
            cout<<depth[a-1] + depth[b-1] - 2*depth[c-1]<<endl;
        }
    }

    return 0;
}