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
    const i64 INF = 1E18;
    vector dis(n + 1, vector<i64>(n + 1, INF));
    for (int i = 0; i <= n; i++) {
        dis[i][i] = 0;
    }

    vector<array<i64, 3>> adj(m + 1);
    for (int i = 1; i <= m; i++) {
        i64 u, v, w;
        cin >> u >> v >> w;
        adj[i] = {u, v, w};
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        i64 ans = 0;
        vector<int> b(k);
        for (int i = 0; i < k; i++) {
            cin >> b[i];
            auto [u, v, w] = adj[b[i]];
            ans += w;
        }

        i64 ned = INF;
        for (int i = 0; i < k; i++) {
            vector<int> st(k);
            st[i] = 1;

            i64 add = INF;
            auto dfs = [&](auto self, int now, int cnt, i64 res) -> void {
                if (cnt == k) {
                    add = min(add, res + (now == n ? 0 : dis[now][n]));
                    return;
                }
                for (int i = 0; i < k; i++) {
                    if (st[i]) {
                        continue;
                    }
                    st[i] = 1;
                    self(self, adj[b[i]][1], cnt + 1, res + dis[now][adj[b[i]][0]]);
                    self(self, adj[b[i]][0], cnt + 1, res + dis[now][adj[b[i]][1]]);
                    st[i] = 0;
                }
            };
            add = INF;
            dfs(dfs, adj[b[i]][0], 1, 0);
            if (adj[b[i]][1] != 1) {
                add += dis[1][adj[b[i]][1]];
            }
            ned = min(ned, add);
            add = INF;
            dfs(dfs, adj[b[i]][1], 1, 0);
            if (adj[b[i]][0] != 1) {
                add += dis[1][adj[b[i]][0]];
            }
            ned = min(ned, add);
        }
        debug(ans, ned);
        cout << ans + ned << '\n';
    }

    return 0;
}