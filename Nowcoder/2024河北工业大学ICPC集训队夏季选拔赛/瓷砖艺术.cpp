#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto& s : v) cin >> s;

    vector<vector<int>> st(n, vector<int>(m));
    constexpr int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    constexpr int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
    map<char, int> ans, mp;

    auto dfs = [&](auto self, int x, int y) -> void {
        mp[v[x][y]]++;
        st[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 or ny < 0) continue;
            if (nx >= n or ny >= m) continue;
            if (st[nx][ny] or v[nx][ny] == '#') continue;
            self(self, nx, ny);
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] != '#' and st[i][j] == 0) {
                mp.clear();
                dfs(dfs, i, j);
                int cnt = 0;
                char col = '#';
                for (auto& [x, y] : mp) {
                    if (y > cnt) {
                        cnt = y;
                        col = x;
                    }
                }
                ans[col]++;
            }
        }
    }
    for (auto& [col, cnt] : ans) { cout << col << ' ' << cnt << '\n'; }

    return 0;
}