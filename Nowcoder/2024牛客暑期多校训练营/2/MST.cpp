#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Info {
    int u, v;
    i64 w;
    bool operator<(const Info& t) const { return w < t.w; }
};

struct query {
    vector<int> point;
    vector<Info> adj;
    i64 Kruskal(int n) {
        i64 res = 0;
        int cnt = 0, k = point.size();
        vector<int> p(n + 1);
        for (auto& x : point) p[x] = x;
        sort(adj.begin(), adj.end());

        function<int(int)> find = [&](int x) {
            return p[x] = (p[x] == x ? x : find(p[x]));
        };

        for (auto [u, v, w] : adj) {
            u = find(u), v = find(v);
            if (u != v) {
                res += w;
                cnt++;
                p[u] = v;
            }
        }
        if (cnt != k - 1) res = -1;
        return res;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m, q;
    cin >> n >> m >> q;
    vector<Info> edge;
    for (int i = 1; i <= m; i++) {
        int u, v;
        i64 w;
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }

    vector<set<int>> st(n + 1);
    vector<query> qry(q);
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        vector<int> point;
        for (int j = 0; j < k; j++) {
            int u;
            cin >> u;
            point.push_back(u);
            st[u].insert(i);
        }
        qry[i].point = point;
    }

    for (auto& [u, v, w] : edge) {
        if (st[u].size() > st[v].size()) swap(u, v);
        for (auto& have : st[u]) {
            if (st[v].count(have)) qry[have].adj.push_back({u, v, w});
        }
    }

    for (auto& i : qry) cout << i.Kruskal(n) << '\n';

    return 0;
}