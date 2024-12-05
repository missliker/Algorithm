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
    vector<int> a(n + 1), b(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        p[i] = i + 1;
    }
    sort(p.begin() + 1, p.end(), [&](int i, int j) {
        if (b[i] == b[j]) {
            return a[i] < a[j];
        }
        return b[i] > b[j];
    });

    i64 ans = 0;
    vector<int> t;
    auto dfs = [&](this auto&& self, int u, i64 w) -> void {
        if (u == n + 1) {
            if (w <= m) {
                i64 res = 0;
                for (int i = 0; i < t.size(); i++) {
                    if (t.size() >= i) {
                        res += 1LL * (int(t.size()) - 1 - i) * t[i];
                    }
                }
                debug(t.size(), res);
                ans = max(ans, res);
            }
            return;
        }
        self(u + 1, w);
        if (w + a[p[u]] <= m) {
            t.emplace_back(b[p[u]]);
            self(u + 1, w + a[p[u]]);
            t.pop_back();
        }
    };
    dfs(1, 0);
    cout << ans << '\n';

    return 0;
}