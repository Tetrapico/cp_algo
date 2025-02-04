#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
int n, m;
vector<vector<int>> adj;
vector<int> circuit;
stack<int> stk;
map<pair<int, int>, bool> used;
 
void findEulerianCircuit(int start) {
    stk.push(start);
    
    while (!stk.empty()) {
        int u = stk.top();
        bool found = false;
 
        while (!adj[u].empty()) {
            int v = adj[u].back();
            adj[u].pop_back();
 
            if (used[{u, v}]) continue; // Already used this edge
            used[{u, v}] = used[{v, u}] = true;
            
            stk.push(v);
            found = true;
            break;
        }
 
        if (!found) {
            circuit.push_back(u);
            stk.pop();
        }
    }
}
 
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
    adj.resize(n + 1);
    vector<int> degree(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
 
    // Step 1: Check if node 1 has edges
    if (adj[1].empty()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    // Step 2: Check if all degrees are even
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 == 1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
 
    // Step 3: Check Connectivity (DFS)
    vector<bool> visited(n + 1, false);
    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) dfs(v);
        }
    };
 
    dfs(1);  // Only visit nodes reachable from node 1
 
    for (int i = 1; i <= n; i++) {
        if (!adj[i].empty() && !visited[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
 
    // Step 4: Find Eulerian Circuit
    findEulerianCircuit(1);
 
    // Check if we used all edges
    if (circuit.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    // Step 5: Print Eulerian Circuit
    reverse(circuit.begin(), circuit.end());
    for (int v : circuit) cout << v << " ";
    cout << "\n";
 
    return 0;
}
