#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
constexpr int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
#define deg(a) cerr << #a << " = " << a << ' ';
#define bug(a) cerr << #a << " = " << a << '\n';

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    vector<string> s(2);
    for (int i = 0; i < 2; i++) cin >> s[i];

    vector<vector<int>> st(2, vector<int>(n));
    int res = 0;
    auto dfs = [&](auto self, int x, int y, int cnt) -> void {
        res = max(res, cnt);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 or ny < 0) continue;
            if (nx >= 2 or ny >= n) continue;
            if (st[nx][ny] or s[nx][ny] == 'W') continue;
            st[nx][ny] = 1;
            self(self, nx, ny, cnt + 1);
        }
    };
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'R' and !st[i][j]) {
                res = 0;
                dfs(dfs, i, j, 0);
                ans = max(ans, res);
                deg(i);
                bug(j);
                bug(res);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}