#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>

using i64 = int64_t;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<i64> u(m + 1), v(m + 1), t(m + 1);
    vector d(n + 1, vector(n + 1, numeric_limits<i64>::max() / 2));
    for (int i = 1; i <= n; i += 1) d[i][i] = 0;
    for (int i = 1; i <= m; i += 1) {
        cin >> u[i] >> v[i] >> t[i];
        d[u[i]][v[i]] = min(d[u[i]][v[i]], t[i]);
        d[v[i]][u[i]] = min(d[v[i]][u[i]], t[i]);
    }
    for (int k = 1; k <= n; k += 1)
        for (int i = 1; i <= n; i += 1)
            for (int j = 1; j <= n; j += 1) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int q;
    cin >> q;
    for (int qi = 0, k; qi < q; qi += 1) {
        cin >> k;
        vector<int> b(k);
        for (int& bi : b) cin >> bi;
        i64 ans = numeric_limits<i64>::max();
        do {
            i64 fu = d[1][v[b[0]]], fv = d[1][u[b[0]]];
            for (int i = 1; i < k; i += 1) tie(fu, fv) = pair(min(fu + d[u[b[i - 1]]][v[b[i]]], fv + d[v[b[i - 1]]][v[b[i]]]), min(fu + d[u[b[i - 1]]][u[b[i]]], fv + d[v[b[i - 1]]][u[b[i]]]));
            ans = min(ans, min(fu + d[u[b.back()]][n], fv + d[v[b.back()]][n]));
        } while (ranges::next_permutation(b).found);
        for (int bi : b) ans += t[bi];
        cout << ans << "\n";
    }
}