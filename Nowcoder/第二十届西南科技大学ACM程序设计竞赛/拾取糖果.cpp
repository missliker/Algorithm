#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using ld = long double;
constexpr ld INF = 1E15 + 10;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    map<ld, int> mp;
    int zero = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x == 0 and y == 0) {
            zero++;
            continue;
        }
        if (x == 0) {
            mp[INF]++;
            continue;
        }
        if (y == 0) {
            mp[0]++;
            continue;
        }
        ld k = y * 1.0 / x;
        mp[k]++;
    }
    int ans = 0;
    // for (auto& [k, cnt] : mp) {
    //     // BUG
    //     cerr << k << ' ' << cnt << '\n';
    // }
    for (auto& [k, cnt] : mp) ans = max(ans, cnt);
    cout << ans + zero << '\n';

    return 0;
}