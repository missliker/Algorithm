#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;
constexpr i64 INF = 1E18 + 10;

struct Info {
    int u;
    i64 d;
    Info() { u = 0, d = 0; }
    Info(int u, i64 d) : u(u), d(d) {}
};
bool operator<(const Info& lth, const Info& rth) { return lth.d > rth.d; }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector adj(n + 1, vector<Pair>());
    vector dis(n + 1, vector<i64>(n + 1, INF));
    for (int i = 0; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }
    set<int> p;
    vector a(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
        p.insert(a[i]);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        for (int j = i + 1; j <= k; j++) {
            if (dis[a[i]][a[j]] < INF) {
                adj[a[i]].emplace_back(a[j], dis[a[i]][a[j]]);
                adj[a[j]].emplace_back(a[i], dis[a[j]][a[i]]);
            }
        }
    }

    i64 res = 0, cnt = 0, mx = 0;
    priority_queue<Info> heap;
    heap.emplace(a[1], 0);

    vector dist(n + 1, INF);
    vector st(n + 1, 0);
    dist[a[1]] = 0LL;

    while (not heap.empty()) {
        if (cnt >= k) break;
        auto [u, d] = heap.top();
        heap.pop();
        if (st[u]) continue;
        st[u] = 1;
        cnt++;
        res += d;
        mx = max(mx, d);
        for (auto& [v, w] : adj[u]) {
            if (w < dist[v]) {
                dist[v] = w;
                heap.emplace(v, w);
            }
        }
    }
    if (cnt != k or t == 0) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (p.find(i) != p.end()) continue;
        i64 mn = INF;
        for (auto& j : p) {
            mn = min(mn, dis[i][j] * 2);
        }
        mx = max(mx, mn);
    }
    if (mx >= INF) {
    	cout << "-1\n";
    	return 0;
    }

    cout << (mx - 1) / t + 1 << '\n';

    return 0;
}