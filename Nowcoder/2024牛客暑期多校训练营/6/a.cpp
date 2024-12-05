#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using Pair = pair<i64, i64>;

void Solution(int T) {
    int n;
    cin >> n;
    vector adj(n + 1, vector<Pair>());
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<int> dep(n + 1), s(n + 1), leaf;
    vector<array<int, 21>> fa(n + 1);
    auto dfs = [&](auto self, int u, int p) -> void {
        dep[u] = dep[p] + 1;
        fa[u][0] = p;
        if (adj[u].size() == 1) {
            leaf.emplace_back(u);
        }
        for (int i = 1; i <= 20; i++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto& [v, w] : adj[u]) {
            if (v == p) continue;
            s[v] = s[u] + w;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    for (int i = 1; i <= n; i++) {
        cout << dep[i] << " \n"[i == n];
    }
    for (int i = 1; i <= n; i++) {
        cout << s[i] << " \n"[i == n];
    }
    for (int i = 0; i < leaf.size(); i++) {
        cout << leaf[i] << " \n"[i == leaf.size() - 1];
    }

    auto lca = [&](int u, int v) -> int {
        if (dep[u] < dep[v]) {
            swap(u, v);
        }
        for (int i = 20; i >= 0; i--) {
            if (dep[fa[u][i]] >= dep[v]) {
                u = fa[u][i];
            }
        }
        if (u == v) {
            return v;
        }
        for (int i = 20; i >= 0; i--) {
            if (fa[u][i] != fa[v][i]) {
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return fa[u][0];
    };

    for (int i = 0; i < leaf.size(); i++) {
        auto dfs2 = [&](auto self, int u, int pa) -> void {
            for (auto& [v, w] : adj[u]) {
            	if (dep[v] >= dep[u]) continue;
            	if (dep[v] & 1) {

            	} else {

            	}
            	self(self, v, pa);
            }
        };
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}