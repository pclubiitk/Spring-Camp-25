#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define tr(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define w(a) while (a--)
#define cint(n) int n; cin >> n;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
#define INF 1e9
#define MOD 1000000007
 
vs graph(1000);
vector<vector<char>> steps(1000, vector<char>(1000));
bool vis[1000][1000];
pi start;
string ans;
int n, m;
 
bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == false && graph[x][y] != '#');
}
 
void back(int x, int y) {
    if (steps[x][y] != 'X') {
        ans.push_back(steps[x][y]);
        if (steps[x][y] == 'U') back(x+1, y);
        else if (steps[x][y] == 'D') back(x-1, y);
        else if (steps[x][y] == 'L') back(x, y+1);
        else if (steps[x][y] == 'R') back(x, y-1);
    }
}
 
bool bfs(int x, int y) {
    steps[x][y] = 'X';
    bool flag = false;
    queue<pi> q;
    q.push({x, y});
    while(!q.empty()) {
        pi pos = q.front();
        x = pos.first; y = pos.second;
        q.pop();
        if (graph[x][y] == 'B') {
            flag = true;
            break;
        }
        vis[x][y] = true;
        if (valid(x-1, y)) {
            vis[x-1][y] = true;
            steps[x-1][y] = 'U';
            q.push({x-1, y});
        }
        if (valid(x+1, y)) {
            vis[x+1][y] = true;
            steps[x+1][y] = 'D';
            q.push({x+1, y});
        }
        if (valid(x, y-1)) {
            vis[x][y-1] = true;
            steps[x][y-1] = 'L';
            q.push({x, y-1});
        }
        if (valid(x, y+1)) {
            vis[x][y+1] = true;
            steps[x][y+1] = 'R';
            q.push({x, y+1});
        }
    }
    if (flag) {
        back(x, y);
        return true;
    } else return false;
}
int main() {
    cin >> n >> m;
    rep(i, 0, n) cin >> graph[i];
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (graph[i][j] == 'A') start = {i, j}; 
        }
    }
    if (bfs(start.first, start.second)) {
        cout << "YES" << endl << ans.size() << endl;
        reverse(ans.begin(), ans.end());
        cout << ans;
    } else cout << "NO" << endl;
}