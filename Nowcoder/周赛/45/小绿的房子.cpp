#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dis(n);
    auto bfs = [&](int x) {
        dis.assign(n, -1);
        queue<int> q;
        dis[x] = 0;
        q.push(x);

        while (not q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto& v : adj[u]) {
                if (dis[v] != -1) continue;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }

        int t = -1;
        for (int i = 0; i < n; i++) {
            if (t == -1 or dis[i] > dis[t]) t = i;
        }
        return t;
    };

    auto a = bfs(0);
    auto b = bfs(a);
    auto f = dis;
    bfs(b);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        f[i] = max(f[i], dis[i]);
        ans += f[i] <= 2;
    }
    cout << ans << '\n';

    return 0;
}