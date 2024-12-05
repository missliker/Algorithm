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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n + 1);
    vector<int> in(n + 1);
    vector<i64> f(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        in[v]++;
        adj[u].emplace_back(v);
    }

    auto check = [&](i64 x) {
        queue<int> q;
        auto in2 = in;
        for (int i = 1; i <= n; i++) {
            if (in2[i] == 0) {
                q.emplace(i);
                f[i] = x;
            } else {
                f[i] = 0;
            }
        }
        while (not q.empty()) {
            int u = q.front();
            q.pop();
            i64 now = f[u];
            if (now >= a[u]) {
                // 得吃
                now += a[u];
            } else {
                // 被扫黄了
                now -= a[u] - f[u];
            }
            for (auto v : adj[u]) {
                if (--in2[v] == 0) {
                    q.emplace(v);
                }
                if (now > 0) {
                    f[v] = max(f[v], now);
                }
            }
        }
        if (f[n] < a[n]) {
            f[n] -= a[n] - f[n];
        }
        return f[n] > 0;
    };

    i64 lo = 0, hi = 1E18;
    while (lo < hi) {
        i64 mi = (lo + hi) / 2;
        if (check(mi)) {
            hi = mi;
        } else {
            lo = mi + 1;
        }
    }
    cout << hi << '\n';

    return 0;
}