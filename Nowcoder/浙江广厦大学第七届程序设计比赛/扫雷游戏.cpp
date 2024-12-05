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
    vector<vector<int>> a(n, vector<int>(m));
    constexpr int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    constexpr int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '*') {
                a[i][j] = -1;
                continue;
            }
            int cnt = 0;
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 or y < 0) continue;
                if (x >= n or y >= m) continue;
                if (v[x][y] == '*') cnt++;
            }
            a[i][j] = cnt;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j] << " \n"[j == m - 1];
    }

    return 0;
}