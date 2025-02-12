#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

int n,m;
vector<string> grid(1000);
vvi visited(1000, vi (1000));

bool valid(int x,int y){
    return (x>=0 && y>=0 && x<n && y<m && grid[x][y]!='#' && !visited[x][y]);
}

void dfs(int x,int y){
    if(visited[x][y]) return;
    visited[x][y]=1;
    if(valid(x,y+1)){
        dfs(x,y+1);
    }
    if(valid(x,y-1)){
        dfs(x,y-1);
    }
    if(valid(x+1,y)){
        dfs(x+1,y);
    }
    if(valid(x-1,y)){
        dfs(x-1,y);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    rep(i,0,n-1) cin>>grid[i];
    int count=0;
    rep(i,0,n-1){
        rep(j,0,m-1){
            if(valid(i,j)){
                dfs(i,j);
                ++count;
            }
        }
    }
    cout<<count;
    return 0;
}