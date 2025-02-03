#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int n;
    vector<vector<int>> adj, rev_adj;
    vector<bool> visited;

    Graph(int n) : n(n), adj(n + 1), rev_adj(n + 1), visited(n + 1, false) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        rev_adj[v].push_back(u); // Reverse graph for checking reachability
    }

    void dfs(int node, vector<vector<int>> &graph) {
        visited[node] = true;
        for (int neighbor : graph[node])
            if (!visited[neighbor]) dfs(neighbor, graph);
    }

    void checkConnectivity() {
        fill(visited.begin(), visited.end(), false);
        dfs(1, adj);  // Check reachability from node 1

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                cout << "NO\n" << 1 << " " << i << "\n";
                return;
            }
        }

        fill(visited.begin(), visited.end(), false);
        dfs(1, rev_adj);  // Check if all nodes can reach node 1

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                cout << "NO\n" << i << " " << 1 << "\n";
                return;
            }
        }

        cout << "YES\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    Graph graph(n);

    while (m--) {
        int a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }

    graph.checkConnectivity();
    return 0;
}
