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

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    i64 ans = 0;
    vector<int> p, rep;
    auto dfs = [&](auto self, int u, int cnt, i64 res) -> void {
        if (u == n + 1) {
            ans = max(ans, res);
            return;
        }
        if (cnt & 1) {
            p.emplace_back(a[u]);
            p.emplace_back(a[u]);
            self(self, u + 1, cnt + 1, res + 2LL * a[u]);
            p.pop_back();
            p.pop_back();
            self(self, u + 1, cnt, res);
        } else {
            p.emplace_back(a[u]);
            self(self, u + 1, cnt + 1, res + a[u]);
            p.pop_back();
            self(self, u + 1, cnt, res);
        }
    };
    dfs(dfs, 1, 0, 0);
    cout << ans << '\n';

    return 0;
}