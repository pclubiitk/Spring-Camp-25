
#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define f first
#define s second
#define all(v) v.begin(),v.end()
ll n, m;
vector<string> grid;
vector<vector<ll>> dist, parent;
vector<pair<ll, ll>> p = { {1,0}, {-1,0}, {0,1}, {0,-1} };
char dir[] = {'D', 'U', 'R', 'L'};
pair<ll, ll> st, ed;
 
void bfs(ll x, ll y) {
    queue<pair<ll, ll>> q;
    q.push({x, y});
    dist[x][y] = 0;
 
    while (!q.empty()) {
        auto temp = q.front(); q.pop();
        for (ll i = 0; i < 4; i++) {
            ll xd = temp.f + p[i].f, yd = temp.s + p[i].s;
            if (xd < 0 || yd < 0 || xd >= n || yd >= m || grid[xd][yd] == '#' || dist[xd][yd] != -1) continue;
            dist[xd][yd] = dist[temp.f][temp.s] + 1;
            parent[xd][yd] = i; 
            q.push({xd, yd});
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    grid.resize(n);
    dist.assign(n, vector<ll>(m, -1));
    parent.assign(n, vector<ll>(m, -1));
 
    for (ll i = 0; i < n; i++) {
        cin >> grid[i];
        for (ll j = 0; j < m; j++) {
            if (grid[i][j] == 'A') st = {i, j};
            if (grid[i][j] == 'B') ed = {i, j};
        }
    }
 
    bfs(st.f, st.s);
 
    if (dist[ed.f][ed.s] == -1) {
        cout << "NO"<<endl;
        return 0;
    }
 
    cout << "YES\n" << dist[ed.f][ed.s] << endl;
 
    string res = "";
    pair<ll, ll> temp = ed;
    ll th=dist[ed.f][ed.s];
    while (th--) {
        ll d = parent[temp.f][temp.s];
        res += dir[d];
        temp = {temp.f - p[d].f, temp.s - p[d].s};
    }
 
    reverse(all(res));
    cout << res << endl;
}


