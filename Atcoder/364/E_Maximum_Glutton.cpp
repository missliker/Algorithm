#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N + 1), B(N + 1);
    vector dp(N + 1, vector<int>(X + 1, Y + 1));
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }

    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j >= 1; j--) {
            for (int k = X; k >= A[i]; k--) {
                dp[j][k] = min(dp[j][k], dp[j - 1][k - A[i]] + B[i]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int x = 0; x <= X; x++) {
            if (dp[i][x] <= Y) ans = max(ans, i + 1);
        }
    }
    cout << ans << endl;

    return 0;
}