#include <bits/stdc++.h>
#define ll long long
#define vpll vector<pair<ll,ll>>
#define vll vector<ll>
#define vdll vector<vector<ll>>
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f first
#define s second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
ll n, m;
vdll vis(1002, vll(1002, 0));
vpll p = { {1,0},{-1,0},{0,1},{0,-1} };
vector<string> grid(1002);
pair<ll, ll> st, ed;
queue<pair<ll, ll>> q;
map<pair<ll, ll>, ll> mp;
map<pair<ll, ll>, pair<ll, ll>> parent;

void bfs(ll x, ll y)
{
    vis[x][y] = 0;
    q.push({x, y});
    mp[{x, y}] = 0; 

    while (!q.empty())
    {
        pair<ll, ll> temp = q.front();
        q.pop();

        for (auto z : p)
        {
            ll xd = temp.f + z.f;
            ll yd = temp.s + z.s;
            if (xd < 0 || yd < 0 || xd >= n || yd >= m) continue;
            if (grid[xd][yd] == '#') continue;
            if (mp.find({xd, yd}) == mp.end())
            {                
                mp[{xd, yd}] = mp[{temp.f, temp.s}] + 1;
                parent[{xd, yd}] = {temp.f, temp.s};
                q.push({xd, yd});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> grid[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A') st = {i, j};
            if (grid[i][j] == 'B') ed = {i, j};
        }
    }

    bfs(st.f, st.s);

    if (mp.find(ed) == mp.end()) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    cout << mp[ed] << "\n";

    string res = "";
    pair<ll, ll> temp = ed;
    ll th=mp[ed];
    while (th--)
    {
        pair<ll, ll> pa = parent[temp];
        if (pa.f - temp.f == 1) res += 'U';
        if (pa.f - temp.f == -1) res += 'D';
        if (pa.s - temp.s == 1) res += 'L';
        if (pa.s - temp.s == -1) res += 'R';
        temp = pa;
    }

    reverse(all(res));
    cout << res << endl;
}
