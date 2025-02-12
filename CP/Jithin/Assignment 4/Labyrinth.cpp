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
// Shortest path automatically comes in bfs since it checks all points at same distance.
vector<vector<char>> moves(1000,vector<char> (1000));

bool valid(int x,int y){
    return (x>=0 && y>=0 && x<n && y<m && grid[x][y]!='#' && !visited[x][y]);
}

bool bfs(int x, int y){
    queue<pi> q;
    q.push({x,y});
    bool reached=false;
    while(!q.empty()){
        pi cur=q.front();
        q.pop();
        int x=cur.F;
        int y=cur.S;
        visited[x][y]=1;
        if(grid[x][y]=='B'){
            reached=true;
            break;
        }
        if(valid(x,y+1)){
            visited[x][y+1]=1;
            moves[x][y+1]='R';
            q.push({x,y+1});
        }
        if(valid(x,y-1)){
            visited[x][y-1]=1;
            moves[x][y-1]='L';
            q.push({x,y-1});
        }
        if(valid(x+1,y)){
            visited[x+1][y]=1;
            moves[x+1][y]='D';
            q.push({x+1,y});
        }
        if(valid(x-1,y)){
            visited[x-1][y]=1;
            moves[x-1][y]='U';
            q.push({x-1,y});
        }
    }
    return reached;
}

vector<char> ans;
void backtrack(int x, int y){
    char curMove=moves[x][y];
    if(curMove=='U'){
        ans.emplace_back(curMove);
        backtrack(x+1,y);
    }
    if(curMove=='D'){
        ans.emplace_back(curMove);
        backtrack(x-1,y);
    }
    if(curMove=='L'){
        ans.emplace_back(curMove);
        backtrack(x,y+1);
    }
    if(curMove=='R'){
        ans.emplace_back(curMove);
        backtrack(x,y-1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    rep(i,0,n-1) cin>>grid[i];
    pi start,end;
    rep(i,0,n-1){
        rep(j,0,m-1){
            if(grid[i][j]=='A') start={i,j};
            if(grid[i][j]=='B') end={i,j};
        }
    }
    if(bfs(start.F,start.S)){
        cout<<"YES\n";
        backtrack(end.F,end.S);
        cout<<ans.size()<<"\n";
        rep(i,0,ans.size()-1){
            cout<<ans[ans.size()-1-i];
        }
    } else cout<<"NO";
    return 0;
}