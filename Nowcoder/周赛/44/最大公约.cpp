#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;
    map<int, int> mp;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
        mx = max(mx, x);
    }
    for (auto& [x, y] : mp) {
        int now = x + x;
        while (now <= mx) {
            if (mp.count(now)) mp[now] += y;
            now += x;
        }
    }
    int ans = 0;
    for (auto& [x, y] : mp) ans = max(ans, y);
    cout << ans << '\n';

    return 0;
}