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

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    using Pair = pair<int, int>;
    vector adj(n + 1, vector<Pair>());
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i > 1; i--) {
        adj[i].emplace_back(i - 1, a[i]);
    }
    adj[1].emplace_back(n, a[1]);
    for (int i = 1; i < n; i++) {
        adj[i].emplace_back(i + 1, a[i]);
    }
    adj[n].emplace_back(1, a[n]);

    const i64 INF = 1E18;
    auto dij = [&](int n, int s) {
        vector<i64> dist(n + 1, INF);
        vector<int> st(n + 1);
        dist[s] = 0LL;
        priority_queue<Pair, vector<Pair>, greater<Pair>> heap;
        heap.push({0LL, s});
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            i64 u = t.second, dis = t.first;

            if (st[u]) continue;
            st[u] = true;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > dis + w) {
                    dist[v] = dis + w;
                    heap.push({dist[v], v});
                }
            }
        }

        return dist;
    };
    auto dis = dij(n, 1);
    debug(dis);

    return 0;
}