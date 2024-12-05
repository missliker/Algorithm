#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector a(n, vector<int>(n));
    vector b(m, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    vector ans(m - n + 1, vector<int>(m - n + 1));
    for (int i = 0; i < m - n + 1; i++) {
        for (int j = 0; j < m - n + 1; j++) {
            for (int ai = 0; ai < n; ai++) {
                for (int aj = 0; aj < n; aj++) {
                    ans[i][j] += a[ai][aj] * b[i + ai][j + aj];
                }
            }
            cout << ans[i][j] << " \n"[j == m - n];
        }
    }

    return 0;
}