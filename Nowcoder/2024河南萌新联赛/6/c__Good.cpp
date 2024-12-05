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
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }

    int ans = 0;
    auto dfs = [&](auto self, int u, int have, int wei, int cnt) -> void {
        if (u == n + 1) {
            if (have <= m and wei % 16 == 0) {
                ans = max(ans, cnt);
            }
            return;
        }
        if (have + v[u] <= m) {
            self(self, u + 1, have + v[u], wei + w[u], cnt + 1);
        }
        self(self, u + 1, have, wei, cnt);
    };
    dfs(dfs, 1, 0, 0, 0);
    cout << ans << '\n';

    return 0;
}