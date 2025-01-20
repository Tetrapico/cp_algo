#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100005];  // Adjacency list for the graph
int team[100005];         // To store the team assignments (1 or 2)
bool visited[100005];     // To track visited nodes

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    team[start] = 1;  // Start with team 1

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (team[v] == 0) {  // If not yet assigned a team
                team[v] = (team[u] == 1) ? 2 : 1;  // Assign opposite team
                q.push(v);
            } else if (team[v] == team[u]) {
                return false;  // Conflict, not bipartite
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Reading the friendships
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Initialize the team array and visited array
    fill(team, team + n + 1, 0);  // 0 means unassigned

    // Try to assign teams to each component
    for (int i = 1; i <= n; ++i) {
        if (team[i] == 0) {  // Not yet visited
            if (!bfs(i)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    // If successful, print the team assignments
    for (int i = 1; i <= n; ++i) {
        cout << team[i] << " ";
    }
    cout << endl;

    return 0;
}
