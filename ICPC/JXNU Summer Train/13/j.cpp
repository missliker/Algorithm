#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 INF = 1E18;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector b(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }

    vector dp(n + 1, vector<i64>(m + 1));
    for (int i = 2; i <= m; i++) {
        dp[0][i] = INF;
    }
    for (int i = 2; i <= n; i++) {
        dp[i][0] = INF;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + b[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = 1LL * a[i][j] - a[1][1] - dp[i][j];
        }
    }

    int ok = 0;
    auto dfs = [&](auto self, int x, int y) -> void {
        if (ok) return;
        if (x == n or y == m) {
            ok = 1;
            return;
        }
        if (y < m and dp[x][y + 1] >= 0) {
            self(self, x, y + 1);
        }
        if (x < n and dp[x + 1][y] >= 0) {
            self(self, x + 1, y);
        }
    };
    dfs(dfs, 1, 1);
    cout << (ok ? "YES" : "NO") << '\n';

    return 0;
}