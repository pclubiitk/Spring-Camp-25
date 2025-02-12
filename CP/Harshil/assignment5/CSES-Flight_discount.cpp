#include <bits/stdc++.h>
using namespace std;

struct Edge 
{
    int to, weight;
};
    
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> graph(n + 1);
    for(int i=0;i<m;i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    
    // distances[node][0] = cost with discount available, 
    // distances[node][1] = cost with discount used.
    vector<vector<int>> distances(n+1, vector<int>(2, INT_MAX));
    distances[1][0] = 0;
    
    // PQ stores {cost, {node, usedDiscount (0 or 1)}}
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    pq.push({0, 1, 0});
    
    while(!pq.empty())
    {
        auto [d, u, used] = pq.top();
        pq.pop();
        
        if(d != distances[u][used]) continue;
        
        for(const Edge &edge : graph[u])
        {
            int v = edge.to;
            int w = edge.weight;
            
            // Without using discount.
            if(d + w < distances[v][used])
            {
                distances[v][used] = d + w;
                pq.push({distances[v][used], v, used});
            }
            // Use discount if not used yet.
            if(used == 0 && d + w/2 < distances[v][1])
            {
                distances[v][1] = d + w/2;
                pq.push({distances[v][1], v, 1});
            }
        }
    }
    
    int ans = min(distances[n][0], distances[n][1]);
    cout << ans << "\n";
    return 0;
}