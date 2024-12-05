#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector adj(n + 1, vector<Pair>());
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int s, t;
    cin >> s >> t;

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
                if (dist[v] > max(dis, w)) {
                    dist[v] = max(dis, w);
                    heap.emplace(dist[v], v);
                }
            }
        }

        return dist;
    };
    auto dis = dij(n, 1);
    cout << dis[t] << '\n';

    return 0;
}