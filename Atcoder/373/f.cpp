#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#ifdef missliker
#include "debug.h"
#else
#define debug(...) void(0)
#endif

i64 dp[310][310];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, W;
    cin >> n >> W;
    vector<i64> w(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= 0; j--) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k * w[i] <= j; k++) {
                if (j >= w[i] * k) {
                    dp[i][j] = max(dp[i][j], dp[i][j - w[i] * k] + k * (v[i] - k));
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = w[i]; j <= W; j++) {
            debug(i, j, dp[i][j]);
        }
    }

    i64 ans = dp[n][W];
    cout << ans << '\n';

    return 0;
}