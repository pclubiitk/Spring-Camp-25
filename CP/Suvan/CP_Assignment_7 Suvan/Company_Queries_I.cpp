// o(n) time complexity

// #include <bits/stdc++.h>
// using namespace std;
// typedef vector<int> vi;
// typedef pair<int,int> pii;
// typedef set<int> s;
// #define sz(a) int((a).size())
// #define pb push_back
// #define all(c) (c).begin(), (c).end()
// #define present(c, x) ((c).find(x) != (c).end())

// void fast_io() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
// }
// vector<vector<int> > adj;
// vi parent;

// void dfs(int vertex,int par = -1) {
//     // Take action on vertex after entering the vertex
//     parent[vertex] = par;
//     for (int child : adj[vertex]) {
//         // Take action on child before entering the child node
//             if(child == par) continue;
//             dfs(child,vertex);
//         // Take action on child after exiting the child node
//     }
//     // Take action on vertex after exiting the vertex
// }

// vector<int> res(int n){
//     vector<int> ans;
//     while(n!=-1){
//         ans.push_back(n+1);
//         n = parent[n];
//     }
//     reverse(all(ans));
//     return ans;
// }

// int main() {
//     fast_io();

//     int test = 1;
//     // cin >> test; 
//     while(test--) {
//         int n,q;
//         cin>>n>>q;
//         adj.assign(n,vi());
//         parent.assign(n,-1);
//         for(int i = 2; i<=n; i++){
//             int a;
//             cin>>a;
//             adj[a-1].push_back(i-1);
//         }
//         dfs(0);
//         for(int i = 0; i<q; i++){
//             int a,b;
//             cin>>a>>b;
//             vi num = res(a-1);
//             int c = num.size()-1;
//             if(c<b){
//                 cout<<"-1"<<endl;
//             }
//             else{
//                 cout<<num[c-b]<<endl;
//             }
//         }
//     }

//     return 0;
// }
       

// o(logn) time complexity


#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

vector<vi> adj;
int mat[200005][20];

void binary_lifting(int vertex,int par){
    mat[vertex][0] = par;
    for(int i = 1; i<20; i++){
        if(mat[vertex][i-1]!=-1){
            mat[vertex][i] = mat[mat[vertex][i-1]][i-1]; 
        }
        else mat[vertex][i] = -1;
    }

    for(int child : adj[vertex]){
        if(child == par) continue;
        binary_lifting(child,vertex);
    }
}

int ans(int start, int k){
    if(start == -1 || k == 0) return start;
    for(int i = 19; i>=0; i--){
        if(k >= (1<<i)){
            return ans(mat[start][i],k-(1<<i));
        }
    }
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
        int n,q;
        cin>>n>>q;
        adj.resize(n);
        for(int i = 2; i<=n; i++){
            int a;
            cin>>a;
            adj[a-1].push_back(i-1);
        }
        binary_lifting(0,-1);
        for(int i = 0; i<q; i++){
            int a,b;
            cin>>a>>b;
            int c = ans(a-1,b);
            if(c!=-1) c +=1;
            cout<<c<<endl;
        }

    }

    return 0;
}