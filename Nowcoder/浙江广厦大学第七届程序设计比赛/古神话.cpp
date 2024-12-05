#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

constexpr i64 P = 10000000007;
constexpr int N = 5E3 + 10;
i64 s[N][N], num[N][N];
i64 sta[N], top;
i64 up[N], down[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) cin >> s[i][j];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) num[i][j] = (s[i][j] == 0) ? num[i][j - 1] + 1 : 0;

    i64 ans = 0;
    for (int j = 1; j <= m; ++j) {
        top = 0;
        for (int i = 1; i <= n; ++i) {
            if (num[i][j]) {
                up[i] = 1;
                while (top and num[i][j] <= num[sta[top]][j]) up[i] += up[sta[top]], --top;
                sta[++top] = i;
            } else {
                top = 0, up[i] = 0;
            }
        }
        top = 0;
        for (int i = n; i >= 1; --i) {
            if (num[i][j]) {
                down[i] = 1;
                while (top and num[i][j] < num[sta[top]][j]) down[i] += down[sta[top]], --top;
                sta[++top] = i;
            } else {
                top = 0, down[i] = 0;
            }
            ans = (ans + ((up[i] % P * down[i] % P) % P * num[i][j]) % P) % P;
        }
    }
    cout << ans << '\n';
    return 0;
}