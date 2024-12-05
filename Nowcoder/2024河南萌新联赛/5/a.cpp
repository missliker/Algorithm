#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int dp[26][13][33];

void Solution(int T) {
    int x, y, z;
    cin >> x >> y >> z;
    cout << dp[x % 100][y][z] << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    auto get = [&](int x) {
        if (x % 4 == 0 and x % 100 != 0 or x % 400 == 0) return 366;
        return 365;
    };

    dp[24][8][1] = 0;
    for (int i = 24; i >= 0; i--) {
        int reali = 2000 + i;
        vector<int> d = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (get(reali) == 366) d[2]++;
        int mon = 12;
        if (i == 24) mon = 7;
        for (int j = mon; j >= 1; j--) {
            for (int k = d[j]; k >= 1; k--) {
                int tmp = 1;
                if (k < d[j]) {
                    tmp &= 1 - dp[i][j][k + 1];
                    // dp[i][j][k] |= 1 - dp[i][j][k + 1];
                }
                if (j < mon and k <= d[j + 1]) {
                    tmp &= 1 - dp[i][j + 1][k];
                    // dp[i][j][k] |= 1 - dp[i][j + 1][k];
                }
                if (i < 24 and j <= mon and k <= d[j]) {
                    tmp &= 1 - dp[i + 1][j][k];
                    // dp[i][j][k] |= 1 - dp[i + 1][j][k];
                }
                dp[i][j][k] = tmp;
            }
        }
    }

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}