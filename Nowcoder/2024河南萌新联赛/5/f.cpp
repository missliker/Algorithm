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
    vector adj2(n + 1, vector<Pair>());
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj2[v].emplace_back(u, w);
    }

    const i64 INF = 1E18;
    auto dij = [&](int n, int s) {
        vector<i64> dist(n + 1, INF);
        vector<int> st(n + 1);
        dist[s] = 0LL;
        priority_queue<Pair, vector<Pair>, greater<Pair>> heap;
        heap.emplace(0LL, s);
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            i64 u = t.second, dis = t.first;

            if (st[u]) continue;
            st[u] = true;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > dis + w) {
                    dist[v] = dis + w;
                    heap.emplace(dist[v], v);
                }
            }
        }

        return dist;
    };
    auto dis = dij(n, 1);

    auto dij2 = [&](int n, int s) {
        vector<i64> dist(n + 1, INF);
        vector<int> st(n + 1);
        dist[s] = 0LL;
        priority_queue<Pair, vector<Pair>, greater<Pair>> heap;
        heap.emplace(0LL, s);
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            i64 u = t.second, dis = t.first;

            if (st[u]) continue;
            st[u] = true;

            for (auto [v, w] : adj2[u]) {
                if (dist[v] > dis + w) {
                    dist[v] = dis + w;
                    heap.emplace(dist[v], v);
                }
            }
        }

        return dist;
    };
    auto dis2 = dij2(n, 1);

    i64 ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += dis[i] + dis2[i];
    }
    cout << ans << '\n';

    return 0;
}