#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void Solution(int T) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--, c--;
        int ans = 0;
        adj[u].emplace_back(v);

        vector<int> dis(n), p;
        auto bfs = [&](int x) -> void {
            queue<int> q;
            q.emplace(x);
            dis.assign(n, -1);
            dis[x] = 0;
            // p.emplace_back(x);
            while (q.size()) {
                int u = q.front();
                // p.emplace_back(u);
                q.pop();

                for (auto v : adj[u]) {
                    if (dis[v] == -1) {
                        dis[v] = dis[u] + 1;
                        q.push(v);
                    }
                }
            }
        };

        bfs(c);
        // ans = max(ans, dis[c]);
        for (int i = 0; i < n; i++) ans = max(ans, dis[i]);
        // for (auto& x : p) ans =
        cout << ans << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}