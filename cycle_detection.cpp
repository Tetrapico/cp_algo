#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent, cycle;
vector<bool> visited;
int start, cycle_end;

bool dfs(int node, int par) {
    visited[node] = true;
    parent[node] = par;
    
    for (int neighbor : adj[node]) {
        if (neighbor == par) continue; // Ignore the edge leading back to parent
        
        if (visited[neighbor]) { 
            // Cycle detected
            start = neighbor;
            cycle_end = node;
            return true;
        }
        
        parent[neighbor] = node;
        if (dfs(neighbor, node)) return true;
    }
    
    return false;
}

void find_cycle(int n) {
    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                // Reconstruct the cycle
                cycle.push_back(start);
                for (int v = cycle_end; v != start; v = parent[v]) {
                    cycle.push_back(v);
                }
                cycle.push_back(start);
                reverse(cycle.begin(), cycle.end());

                cout << cycle.size() << "\n";
                for (int v : cycle) cout << v << " ";
                cout << "\n";
                return;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    find_cycle(n);
    return 0;
}
