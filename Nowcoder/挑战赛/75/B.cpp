#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m;
    vector<i64> a(n), b(n), c(m), d(m);
    vector<vector<i64>> L(4), R(4);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        L[0].push_back(a[i] + b[i]);
        L[1].push_back(-a[i] + b[i]);
        L[2].push_back(a[i] - b[i]);
        L[3].push_back(-a[i] - b[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i] >> d[i];
        R[0].push_back(c[i] + d[i]);
        R[1].push_back(-c[i] + d[i]);
        R[2].push_back(c[i] - d[i]);
        R[3].push_back(-c[i] - d[i]);
    }
    for (int i = 0; i < 4; i++) {
        sort(L[i].begin(), L[i].end());
        sort(R[i].begin(), R[i].end());
    }
    i64 ans = 0;
    for (int i = 0; i < 4; i++) {
        ans = max(ans, L[i].back() - R[i].front());
        ans = max(ans, R[i].back() - L[i].front());
    }
    cout << ans << '\n';

    return 0;
}