#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector adj(n + 1, vector<int>());
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    vector<int> mx(n + 1);
    for (int u = 1; u <= n; u++) {
    	int t = -1;
    	for (auto& v : adj[u]) {
    		if (t == -1 or a[v] > a[t]) {
    			t = v;
    		}
    	}
    	mx[u] = t;
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> st(n + 1);
        vector<int> path;
        auto dfs = [&](auto self, int u) -> void {
            if (path.size() == min(n, 4)) {
                i64 res = 0;
                for (auto& i : path) {
                    res += a[i];
                }
                int tail = 0;
                for (auto& w : adj[path.back()]) {
                	if (st[w]) continue;
                	tail = max(tail, a[w]);
                }
                res += tail;
                ans = max(ans, res);
                return;
            }
            for (auto& v : adj[u]) {
                if (st[v]) continue;
                st[v] = 1;
                path.emplace_back(v);
                self(self, v);
                st[v] = 0;
                path.pop_back();
            }
        };
        st[i] = 1;
        path.emplace_back(i);
        for (auto& p : adj[i]) {
        	st[p] = 1;
        	path.emplace_back(p);
        	dfs(dfs, i);
        	st[p] = 0;
        	path.pop_back();
        }
    }
    cout << ans << '\n';

    return 0;
}