#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Info {
    int x, y, z;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<int> p(n * 2 + 1);
    iota(p.begin(), p.end(), 0);

    vector<Info> adj(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[i] = {u, v, w};
    }
    sort(adj.begin(), adj.end(), [&](Info lth, Info rth) { return lth.z > rth.z; });

    function<int(int)> find = [&](int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    };

    int ans = 0;
    for (int i = 0; i < m; i++) {
        auto [u, v, w] = adj[i];
        if (find(u) == find(v) or find(u + n) == find(v + n)) {
            ans = w;
            break;
        }
        p[p[u + n]] = p[v];
        p[p[u]] = p[v + n];
    }
    cout << ans << '\n';

    return 0;
}