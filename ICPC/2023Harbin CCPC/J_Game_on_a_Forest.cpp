#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int n, m;
    cin >> n >> m;

    struct DSU {
        vector<int> f, siz;
        DSU(int n) : f(n), siz(n, 1) { iota(f.begin(), f.end(), 0); }
        int leader(int x) {
            while (x != f[x])
                x = f[x] = f[f[x]];
            return x;
        }
        bool same(int x, int y) { return leader(x) == leader(y); }
        bool merge(int x, int y) {
            x = leader(x);
            y = leader(y);
            if (x == y)
                return false;
            siz[x] += siz[y];
            f[y] = x;
            return true;
        }
        int size(int x) { return siz[leader(x)]; }
    };
    DSU dsu(n + 1);

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int SG = 0, ans = 0;
    auto sg = [&](int x) { return (x ? 2 - x % 2 : 0); };

    for (int i = 1; i <= n; i++) {
        if (dsu.leader(i) == i) {
            SG ^= sg(dsu.size(i));
        }
    }

    vector<int> sz(n + 1);
    function<void(int, int)> dfs = [&](int u, int p) {
        sz[u] = 1;
        int sonSG = 0;
        for (auto v : g[u]) {
            if (v != p) {
                dfs(v, u);
                sz[u] += sz[v];
                sonSG ^= sg(sz[v]);
            }
        }
        sonSG ^= sg(dsu.size(u) - sz[u]);
        if ((SG ^ sonSG) == 0) {
            ans += 1;
            // cout << u << endl;
        }
        if (p and (SG ^ sg(sz[u]) ^ sg(dsu.size(u) - sz[u])) == 0) {
            ans += 1;
            // cout << u << "----" << p << endl;
        }
    };

    for (int i = 1; i <= n; i++) {
        if (dsu.leader(i) == i) {
            SG ^= sg(dsu.size(i));
            dfs(i, 0);
            SG ^= sg(dsu.size(i));
        }
    }
    cout << ans;

    return 0;
}