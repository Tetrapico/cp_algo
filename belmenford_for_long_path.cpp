#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Edge {
    int u, v, w;
};

const int INF = 1e18;
int n, m;
vector<Edge> edges;
vector<int> dist;
vector<bool> visited, inQueue;
vector<vector<int>> adj, revAdj;

void dfs(int node) {
    visited[node] = true;
    for (int next : revAdj[node]) {
        if (!visited[next]) dfs(next);
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    edges.resize(m);
    adj.resize(n + 1);
    revAdj.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        edges[i] = {a, b, x};
        adj[a].push_back(b);
        revAdj[b].push_back(a); // Reverse graph for cycle detection
    }

    // Step 1: Bellman-Ford for longest path
    dist.assign(n + 1, -INF);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != -INF && dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 2: Detect positive cycles affecting the path to n
    queue<int> q;
    inQueue.assign(n + 1, false);
    
    for (auto [u, v, w] : edges) {
        if (dist[u] != -INF && dist[u] + w > dist[v]) {
            q.push(v);
            inQueue[v] = true;
        }
    }

    // Step 3: Mark nodes in positive cycles that can reach `n`
    visited.assign(n + 1, false);
    dfs(n);  // Reverse DFS to mark nodes that can reach `n`

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (visited[node]) {
            cout << -1 << '\n';
            return 0;
        }
        for (int next : adj[node]) {
            if (!inQueue[next]) {
                q.push(next);
                inQueue[next] = true;
            }
        }
    }

    // Step 4: Print the max score if no infinite loop is found
    cout << dist[n] << '\n';
    return 0;
}
