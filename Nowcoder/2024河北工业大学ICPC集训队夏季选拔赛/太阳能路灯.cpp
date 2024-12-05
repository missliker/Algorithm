#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 n, t, r;
    cin >> n >> t >> r;
    vector<i64> c(n);
    for (auto& x : c) cin >> x;
    i64 now = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        now += c[i];
        now = min(now, t);
        if (now >= r) {
            now -= r;
        } else {
            now = 0;
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}