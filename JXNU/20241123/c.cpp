#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<i64> f(n + 1);
    f[0] = 2200;
    vector adj(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        i64 fa, val;
        cin >> fa >> val;
        adj[fa].emplace_back(i);
        f[i] = val;
    }

    vector<i64> g(n + 1);
    set<int> ye;
    auto dfs = [&](this auto&& self, int u) -> void {
        if (adj[u].empty()) {
            return;
        }
        for (auto v : adj[u]) {
            self(v);
            if (adj[v].empty()) {
                g[v] = f[v];
                ye.insert(v);
            }
            g[u] += g[v];
        }
    };
    dfs(0);
    debug(g);

    vector<i64> a, b;
    for (int i = 1; i <= n; i++) {
        if (ye.find(i) == ye.end()) {
            a.emplace_back(f[i]);
            b.emplace_back(g[i]);
        }
    }
    ranges::sort(a);
    ranges::sort(b);

    bool ok = f[0] >= g[0];
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < b[i]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';

    return 0;
}