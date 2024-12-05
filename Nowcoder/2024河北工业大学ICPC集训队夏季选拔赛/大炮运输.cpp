#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
constexpr i64 INF = 1E18 + 10;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    auto add = [&](int a, int b, int x) -> i64 {
        return 1LL * a * x * x * x + b;
    };

    vector<i64> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {
        for (i64 j = 1; i + j <= n and j <= 1000; j++) {
            // NOTE
            dp[i + j] = min(dp[i + j], dp[i] + add(a[i], b[i], j));
        }
    }
    cout << dp.back() << '\n';

    return 0;
}