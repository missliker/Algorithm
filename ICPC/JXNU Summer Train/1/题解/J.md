# 题意



# 方法





# 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int N = 85;
int dp[2][2][N][N * N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector d(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        d[u][v] = 1;
    }
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
    int q;
    cin >> q;
    vector<int> x(q + 1);
    for (int i = 1; i <= q; i++) cin >> x[i];
    x[0] = 1;
    int op = 0;
    memset(dp, 0x3f, sizeof dp);
    dp[op][0][1][0] = dp[op][1][1][0] = 0;
    for (int i = 1; i <= q; i++, op ^= 1) {
        for (int j = 1; j <= n; j++) {
            for (int s = 0; s <= n * q; s++) {
                int d1 = d[x[i - 1]][x[i]], d2 = d[j][x[i]];
                // a->q[i-1],b->j ---> a->q[i],b->j
                if (s >= d1) dp[op ^ 1][0][j][s] = min(dp[op ^ 1][0][j][s], dp[op][0][j][s - d1]);
                // a->q[i-1],b->j --> a->q[i-1],b->q[i]
                dp[op ^ 1][1][x[i - 1]][s] = min(dp[op ^ 1][1][x[i - 1]][s], dp[op][0][j][s] + d2);
                // a->j,b->q[i-1] --> a->q[i],b->j
                if (s >= d2) dp[op ^ 1][0][x[i - 1]][s] = min(dp[op ^ 1][0][x[i - 1]][s], dp[op][1][j][s - d2]);
                // a->j,b->q[i-1] --> a->j,b->q[i]
                dp[op ^ 1][1][j][s] = min(dp[op ^ 1][1][j][s], dp[op][1][j][s] + d1);
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int s = 0; s <= n * q; s++) {
                for (int o = 0; o < 2; o++) dp[op][o][j][s] = 0x3f3f3f3f;
            }
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n * q; j++) {
            int sa = j, sb = min(dp[op][0][i][j], dp[op][1][i][j]);
            ans = min(ans, max(sa, sb));
        }
    }
    cout << ans << '\n';

    return 0;
}
```

[题目链接](https://codeforces.com/gym/536487/problem/J)