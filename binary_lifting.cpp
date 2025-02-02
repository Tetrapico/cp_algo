#include <bits/stdc++.h>
using namespace std;

#define int long long
const int LOG = 30; // log2(10^9) ≈ 30

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> up(n + 1, vector<int>(LOG));
    
    // Read teleporters
    for (int i = 1; i <= n; i++) {
        cin >> up[i][0]; // Direct teleport destination
    }

    // Precompute jump table for binary lifting
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j - 1]][j - 1]; // 2^j jump from i
        }
    }

    // Process queries
    while (q--) {
        int x, k;
        cin >> x >> k;

        for (int j = 0; j < LOG; j++) {
            if (k & (1LL << j)) { // If bit j is set in k, jump 2^j
                x = up[x][j];
            }
        }
        cout << x << "\n";
    }

    return 0;
}
