#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
constexpr int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

void Solution(int T) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> st(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (st[i][j]) continue;
            priority_queue<int> q;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 or ny < 0) continue;
                if (nx >= n or ny >= m) continue;
                q.push(a[nx][ny]);
            }
            if (a[i][j] > q.top()) {
                a[i][j] = q.top();
                st[i][j] = 1;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 or ny < 0) continue;
                    if (nx >= n or ny >= m) continue;
                    st[nx][ny] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j] << " \n"[j == m - 1];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int MAXT = 1;
    cin >> MAXT;
    for (int T = 1; T <= MAXT; T++) Solution(T);

    return 0;
}