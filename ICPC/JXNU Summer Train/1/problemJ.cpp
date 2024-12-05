#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int dp[100][100][10000][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, 1E9 + 10));
    for (int i = 0; i <= n; i++) dis[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    int q;
    cin >> q;
    vector<int> x(q + 1);
    for (int i = 1; i <= q; i++) cin >> x[i];
    for (int i = 0; i <= q; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n * m; k++) {
                for (int l = 0; l < 2; l++) dp[i][j][k][l] = 1E9 + 10;
            }
        }
    }

    for (int i = 1; i <= q; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= n * m; k++) {
                if (k >= dis[x[i - 1]][x[i]]) dp[i][j][k][0] = min(dp[i][j][k][0], dp[i - 1][j][k - dis[x[i - 1]][x[i]]][0] + dis[x[i - 1]][x[i]]);
                if (k >= dis[j][x[i]]) dp[i][j][k][0] = min(dp[i][j][k][0], dp[i - 1][x[i - 1]][k - dis[j][x[i]]][1] + dis[j][x[i]]);
                dp[i][j][k][1] = min(dp[i][j][k][1], dp[i - 1][j][k][0] + dis[j][x[i]]);
                dp[i][j][k][1] = min(dp[i][j][k][1], dp[i - 1][j][k][1] + dis[x[i - 1]][x[i]]);
            }
        }
    }
    int ans = 1E9 + 10;
    for (int j = 1; j <= n; j++) {
        for (int k = 0; k <= n * m; k++) {
            for (int l = 0; l < 2; l++) ans = min(ans, dp[q][j][k][l]);
        }
    }
    cout << ans << '\n';

    return 0;
}