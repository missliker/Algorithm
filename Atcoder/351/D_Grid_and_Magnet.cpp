#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
#define deg(a) cerr << #a << " == " << a << ' ';
#define bug(a) cerr << #a << " == " << a << '\n';
constexpr int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
constexpr int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }

    int ans = 0;
    vector<vector<int>> st(n + 1, vector<int>(m + 1));
    auto dfs = [&](auto self, int x, int y, int cnt) -> void {
        if (ans >= 2) return;
        ans = max(ans, cnt);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 or ny < 1) continue;
            if (nx > n or ny > m) continue;
            if (s[nx][ny] == '#' or st[nx][ny]) continue;
            st[nx][ny] = true;
            self(self, nx, ny, cnt + 1);
        }
    };

    int res = 0;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            ans = 0;
            vector<vector<int>> t(n + 1, vector<int>(m + 1));
            swap(st, t);
            dfs(dfs, x, y, 0);
            if (ans >= 2) res++;
        }
    }
    cout << res << '\n';

    return 0;
}