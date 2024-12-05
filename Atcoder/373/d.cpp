#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;
const i64 INF = 1E9 + 114514;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

i64 intRand(i64 mod) { return rng() * rng() % mod; }

i64 intRand(i64 l, i64 r) { return l + intRand(r - l + 1); }

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<vector<Pair>> adj(n);
    vector<int> u(m), v(m);
    vector<i64> w(m);
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
        adj[u[i]].emplace_back(v[i], w[i]);
        adj[v[i]].emplace_back(u[i], -w[i]);
    }
    debug(INF);

    vector<i64> x(n, INF);
    auto dfs = [&](auto self, int u) -> void {
        for (auto& [v, w] : adj[u]) {
            if (x[v] == INF) {
                x[v] = x[u] + w;
                self(self, v);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (x[i] == INF) {
            x[i] = 0;
            dfs(dfs, i);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << x[i] << " \n"[i == n - 1];
    }

    for (int i = 0; i < m; i++) {
        if (x[v[i]] - x[u[i]] != w[i]) {
            cout << "BUG\n";
            return 0;
        }
    }

    return 0;
}