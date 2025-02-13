#include<bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
using std::queue;
using std::vector;

int main() {
	int n = 6;
	vector<vector<int>> adj(n);
	vector<bool> visited(n);

	/*
	 * Define adjacency list and read in problem-specific input
	 *
	 * In this example, we've provided "dummy input" that's
	 * reflected in the GIF above to help illustrate the
	 * order of the recrusive calls.
	 */
	adj[0] = {1, 2, 4};
	adj[1] = {3, 4};
	adj[2] = {5};

	for (int i = 0; i < n; i++) {
		// iterate over all connected components in the graph
		if (!visited[i]) {
			queue<int> q;
			q.push(i);
			visited[i] = true;
			while (!q.empty()) {
				int current_node = q.front();
				q.pop();
				for (int neighbor : adj[current_node]) {
					if (!visited[neighbor]) {
						visited[neighbor] = true;
						q.push(neighbor);
					}
				}
			}
		}
	}
}