#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using d64 = long double;

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
    vector<d64> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<d64> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        d64 mx = 0;
        for (int j = i - 1; j >= 1; j--) {
            d64 dx = x[i] - x[j], dy = y[i] - y[j];
            mx = max(mx, sqrtl(dx * dx + dy * dy));
            dp[i] = max(dp[i], dp[j - 1] + mx);
        }
    }
    cout << dp.back() << '\n';

    return 0;
}