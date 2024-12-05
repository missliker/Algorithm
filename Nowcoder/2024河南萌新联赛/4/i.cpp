#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, x, y;
    cin >> n >> x >> y;
    vector adj(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> path, res{x};
    vector<int> st(n + 1);
    st[x] = 1;
    auto serch = [&](auto self, int u) -> void {
        if (not path.empty()) return;
        for (auto& v : adj[u]) {
            if (st[v]) continue;
            st[v] = 1;
            res.emplace_back(v);
            if (v == y) {
                path = res;
                return;
            }
            self(self, v);
            res.pop_back();
        }
    };
    serch(serch, x);

    vector<int> f(n + 1);
    auto dfs = [&](auto self, int u, int p) -> void {
        f[u] = 1;
        for (auto& v : adj[u]) {
            if (v == p) continue;
            self(self, v, u);
            f[u] += f[v];
        }
    };
    dfs(dfs, x, path[1]);
    dfs(dfs, y, path.end()[-2]);

    cout << 1LL * f[x] * f[y] << '\n';

    return 0;
}