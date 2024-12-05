#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;
const i64 INF = 1E18;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m, s, k, g;
    cin >> n >> m >> s >> k >> g;
    s--;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> e(n), ghost(n);
    for (int i = 0; i < k; i++) {
        int u;
        cin >> u;
        u--;
        e[u] = 1;
    }

    for (int i = 0; i < g; i++) {
        int u;
        cin >> u;
        u--;
        ghost[u] = 1;
    }

    auto dij2 = [&](int n, int s) {
        vector<i64> dist(n, INF);
        vector<int> st(n);
        dist[s] = 0;
        priority_queue<Pair, vector<Pair>, greater<Pair>> heap;
        heap.emplace(0, s);
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            i64 u = t.second, dis = t.first;

            if (st[u]) continue;
            st[u] = true;

            for (auto v : adj[u]) {
                if (dist[v] > dis + 1) {
                    dist[v] = dis + 1;
                    heap.emplace(dist[v], v);
                }
            }
        }

        return dist;
    };
    auto dis = dij2(n, s);

    debug(dis);

    auto dij = [&](int n) {
        vector<i64> dist(n, INF);
        vector<int> st(n);
        priority_queue<Pair, vector<Pair>, greater<Pair>> heap;

        for (int i = 0; i < n; i++) {
            if (ghost[i]) {
                dist[i] = 0;
                heap.emplace(0, i);
                debug(i);
            }
        }

        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            auto [dis, u] = t;
            debug(u);

            if (st[u]) continue;
            st[u] = true;

            for (auto v : adj[u]) {
                if (dist[v] > dis + 1) {
                    dist[v] = dis + 1;
                    heap.emplace(dist[v], v);
                    debug(v, dist[v]);
                }
            }
        }

        return dist;
    };
    auto dist = dij(n);

    debug(dist);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (e[i]) {
            if (dist[i] > dis[i]) {
                ans++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}