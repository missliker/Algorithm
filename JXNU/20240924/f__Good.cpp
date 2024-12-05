#include <bits/stdc++.h>
// #define PI acos(-1)
using namespace std;
typedef long long LL;
const LL N = 2e5 + 16, MOD = 1e9 + 7, INF = 1e18;
typedef pair<LL, LL> PII;
map<LL, LL> mp;
int dx[5] = {0, 0, 1, 0, -1}, dy[5] = {0, 1, 0, -1, 0};
LL n, m, s, k, g, q;
LL out[N], stp[N];
vector<PII> e[N];

void solve() {
    cin >> n >> m >> s >> k >> g;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back({v, 1});
        e[v].push_back({u, 1});
    }
    for (int i = 1, x; i <= k; i++) {
        cin >> out[i];
        mp[out[i]] = i;
    }
    for (int i = 1, x; i <= g; i++) {
        cin >> stp[i];
        // mp[stp[i]]++;
    }

    auto dij = [&](int n) {
        vector<LL> dist(n + 1);
        vector<int> st(n + 1);
        for (int i = 0; i <= n; i++) dist[i] = INF;
        dist[s] = 0ll;
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        heap.push({0ll, s});
        while (heap.size()) {
            auto t = heap.top();
            heap.pop();

            LL u = t.second, dis = t.first;

            if (st[u]) continue;
            st[u] = true;

            for (auto tt : e[u]) {
                LL v = tt.first, w = tt.second;
                if (dist[v] > dis + w) {
                    dist[v] = dis + w;
                    heap.push({dist[v], v});
                }
            }
        }

        return dist;
    };
    auto dis = dij(n);
    LL ans = 0;

    queue<PII> qp;
    vector<int> st(n + 1);
    vector<LL> lst(n + 1);
    for (int i = 0; i <= n; i++) lst[i] = INF;

    for (int i = 1; i <= g; i++) {
        if (mp.count(stp[i])) {
            lst[mp[stp[i]]] = 0;
        }
        qp.push({stp[i], 0});
        st[stp[i]]++;
    }

    while (qp.size()) {
        auto [x, y] = qp.front();
        qp.pop();

        if (mp.count(x)) {
            lst[mp[x]] = min(lst[mp[x]], y);
        }

        for (auto [v, w] : e[x]) {
            if (!st[v]) {
                qp.push({v, y + 1});
                st[v]++;
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        // cout << dis[out[i]] << ' ' << lst[i] << '\n';
        if (dis[out[i]] < lst[i]) ans++;
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(3);
    // freopen("D:\study\test.txt", "r", stdin);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}