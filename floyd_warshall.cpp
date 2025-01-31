#include <bits/stdc++.h>
using namespace std;

#define INF 1e18
typedef long long ll;

void floyd_warshall(int n, vector<vector<ll>> &dist) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) { // Ensure no overflow
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));

    // Initialize self-distances to 0
    for (int i = 1; i <= n; i++) dist[i][i] = 0;

    // Read the edges
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c); // Handle multiple edges
        dist[b][a] = min(dist[b][a], c); // Since roads are two-way
    }

    // Run Floyd-Warshall algorithm
    floyd_warshall(n, dist);

    // Process queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF)
            cout << -1 << "\n";
        else
            cout << dist[a][b] << "\n";
    }

    return 0;
}
