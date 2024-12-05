#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    i64 n, q, t;
    cin >> n >> q >> t;
    vector<i64> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    sort(v.begin() + 1, v.end());
    for (int i = 1; i <= n; i++) v[i] += v[i - 1];
    while (q --) {
        i64 m;
        cin >> m;
        i64 cnt = m / t;
        i64 ans = max(0, v[i - cnt - 1]) + t;
        cout << ans << '\n';
    }
    return 0;
}
