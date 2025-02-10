#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef set<int> s;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())

void fast_io() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

int main() {
	fast_io();

	int test = 1;
	//cin >> test;
	while(test--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);  
        adj[b - 1].push_back(a - 1);  
    }
    
    vector<int> dist(n, -1);
    vector<int> parent(n, -1);
    
    queue<int> q;
    dist[0] = 0; 
    q.push(0);   
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int child : adj[current]) {
            if (dist[child] == -1) { 
                dist[child] = dist[current] + 1;
                parent[child] = current;
                q.push(child);
            }
        }
    }

    if (dist[n - 1] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {

        cout << dist[n - 1] + 1 << endl;
        
        vector<int> path;
        for (int i = n - 1; i != -1; i = parent[i]) {
            path.push_back(i + 1);  
        }
        
        reverse(path.begin(), path.end());
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;

		}
	}
	return 0;
}