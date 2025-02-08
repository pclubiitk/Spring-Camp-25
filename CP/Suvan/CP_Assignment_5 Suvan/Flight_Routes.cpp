#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())
#define INF INT_MAX
vector<vector<pii> > adj;

void path(int n, int m, int k) {

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<vector<long long> > dist(n + 1);  

    pq.push(make_pair(0, 1));  
    dist[1].push_back(0);

    while (!pq.empty()) {
        auto [cur_cost, u] = pq.top();
        pq.pop();

        for (auto [v, price] : adj[u]) {
            long long new_cost = cur_cost + price;

            if (dist[v].size() < k) {
                dist[v].push_back(new_cost);
                pq.push(make_pair(new_cost, v));
            } 

            else if (new_cost < dist[v].back()) {
                dist[v].push_back(new_cost);
                pq.push(make_pair(new_cost, v));
                sort(dist[v].begin(), dist[v].end()); 
                dist[v].pop_back(); 
            }
        }
    }

    sort(dist[n].begin(), dist[n].end());
    for (int i = 0; i < k; i++) {
        cout << dist[n][i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    adj.assign(n + 1, vector<pii>());

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
    }

    path(n, m, k);

    return 0;
}
