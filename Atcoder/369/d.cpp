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

    vector dp(n + 1, vector<i64>(2));
    dp[1][1] = a[1];
    for (int i = 2; i <= n; i++) {
        dp[i][1] = max(dp[i - 1][0], dp[i - 2][0]) + a[i];
        dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]) + 2LL * a[i];
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';

    return 0;
}