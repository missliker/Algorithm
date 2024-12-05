#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    vector<i64> dp(m + 1, 1E18 + 10);
    dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = i - 1; j >= max(0, i - 40); j--) {
            i64 add = pow(i64(i - j), 4);
            dp[i] = min(dp[i], dp[j] + a[i] + add);
        }
    }
    cout << dp[m] << '\n';

    return 0;
}