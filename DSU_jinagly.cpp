#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(m), d(m), k(m);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i] >> d[i] >> k[i];
        a[i]--;
    }
    
    DSU dsu(n);
    int ans = n;
    for (int x = 1; x <= 10; x++) {
        std::vector<int> f(n);
        for (int i = 0; i < m; i++) {
            if (d[i] == x) {
                f[a[i]]++;
                f[a[i] + k[i] * x]--;
            }
        }
        for (int i = x; i < n; i++) {
            f[i] += f[i - x];
        }
        for (int i = 0; i < n; i++) {
            if (f[i]) {
                ans -= dsu.merge(i, i + x);
            }
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
