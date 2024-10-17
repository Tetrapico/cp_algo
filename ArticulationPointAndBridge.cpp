#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;
using ll = long long;

int t;

const int N = 1e5 + 20, inf = 3e18;
int n, m;
vector <int> g[N];

int h[N], dp[N], sz[N];;
vector <int> cands;
bool vis[N];

void dfs(int v) {
	vis[v] = true;
	sz[v] = 1;

	for (int u: g[v]) {
		if (!vis[u]) {
			h[u] = h[v] + 1;
			dfs(u);
			sz[v] += sz[u];
			dp[v] = min(dp[v], dp[u]);
		}
		else {
			if (h[u] == h[v] - 1) continue;
			dp[v] = min(dp[v], h[u]);
		}
	}

	if (dp[v] >= h[v]) {
		cands.push_back(v);
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> t;

	while (t--) {
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			g[i].clear();
			vis[i] = 0;
			sz[i] = 0;
			h[i] = -1;
			dp[i] = inf;
		}

		for (int i = 0, u, v; i < m; i++) {
			cin >> u >> v;
			u--, v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		int best_edge = -inf, sum = 0;

		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				h[i] = 0;
				cands.clear();
				dfs(i);

				sum += (sz[i] - 1) * sz[i] / 2;

				for (int v: cands) {
					best_edge = max(best_edge, sz[v] * (sz[i] - sz[v]));
				}
			}
		}

		cout << sum - best_edge << '\n';
	}
}
