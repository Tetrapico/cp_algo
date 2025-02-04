#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 200005
 
vector<int> adj[MAXN], rev_adj[MAXN], order;
bool visited[MAXN];
int component[MAXN], truth[MAXN];
 
void dfs1(int node) {
    visited[node] = true;
    for (int next : adj[node]) {
        if (!visited[next]) dfs1(next);
    }
    order.push_back(node);
}
 
void dfs2(int node, int comp_id) {
    visited[node] = true;
    component[node] = comp_id;
    for (int next : rev_adj[node]) {
        if (!visited[next]) dfs2(next, comp_id);
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    // Reset global structures
    for (int i = 1; i <= 2 * m; i++) {
        adj[i].clear();
        rev_adj[i].clear();
        visited[i] = false;
        component[i] = 0;
        truth[i] = 0;
    }
    order.clear();
 
    // Read constraints and build implication graph
    for (int i = 0; i < n; i++) {
        char sign1, sign2;
        int a, b;
        cin >> sign1 >> a >> sign2 >> b;
 
        // Convert negative literals
        int varA = (sign1 == '+' ? a : m + a);
        int varB = (sign2 == '+' ? b : m + b);
 
        int notA = (varA > m) ? varA - m : varA + m;
        int notB = (varB > m) ? varB - m : varB + m;
 
        // Add implications
        adj[notA].push_back(varB);  // ¬A → B
        adj[notB].push_back(varA);  // ¬B → A
        rev_adj[varB].push_back(notA);
        rev_adj[varA].push_back(notB);
    }
 
    // Kosaraju's algorithm: First DFS pass (topological order)
    for (int i = 1; i <= 2 * m; i++) {
        if (!visited[i]) dfs1(i);
    }
 
    // Kosaraju's second pass (finding SCCs)
    fill(visited, visited + 2 * m + 1, false);
    int comp_id = 0;
    for (int i = 2 * m - 1; i >= 0; i--) {
        int node = order[i];
        if (!visited[node]) {
            comp_id++;
            dfs2(node, comp_id);
        }
    }
 
    // Check if a variable and its negation are in the same SCC
    for (int i = 1; i <= m; i++) {
        if (component[i] == component[i + m]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        truth[i] = (component[i] > component[i + m]);
    }
  
    // Print the valid solution
    for (int i = 1; i <= m; i++) {
        cout << (truth[i] ? '+' : '-');
    }
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    solve();
    return 0;
}
