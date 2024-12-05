#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    i64 s = 0;
    for (auto& i : a) s += i;
    if (k > s) {
        cout << "-1\n";
        return 0;
    }

    auto check = [&](i64 x) -> bool {
        int cnt = 0;
        i64 now = 0;
        for (int i = 0; i < n; i++) {
            now += a[i];
            if (now >= x) {
                cnt++;
                now = 0;
            }
        }
        // cerr << x << ' ' << cnt << '\n';
        return cnt >= k;
    };

    i64 l = 0, r = 1E13;
    while (l < r) {
        i64 m = (l + r + 1LL) / 2;
        if (check(m)) l = m;
        else r = m - 1;
    }
    cout << r << '\n';

    return 0;
}