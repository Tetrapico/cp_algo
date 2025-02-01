#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e18

struct State {
    ll cost;
    int node;
    bool operator>(const State &other) const {
        return cost > other.cost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, ll>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }

    priority_queue<State, vector<State>, greater<State>> pq;
    vector<vector<ll>> dist(n + 1); // Stores up to k shortest distances for each node

    pq.push({0, 1}); // Start from city 1 (Syrjälä)

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        int u = cur.node;
        ll d = cur.cost;

        // Ignore if already found k shortest paths
        if (dist[u].size() >= k) continue;

        dist[u].push_back(d);

        for (auto &[v, w] : graph[u]) {
            pq.push({d + w, v});
        }
    }

    // Print the k shortest paths to city n (Metsälä)
    for (ll d : dist[n]) {
        cout << d << " ";
    }
    cout << "\n";

    return 0;
}
