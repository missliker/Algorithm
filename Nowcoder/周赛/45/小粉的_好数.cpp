#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin >> n;

    auto f = [&](int x) {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    };

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = i, cnt = f(x);
        bool ok = cnt % 2 == 0;
        if (ok) {
            while (cnt < x) {
                if (cnt & 1) {
                    ok = false;
                    break;
                }
                x = f(x);
                cnt = f(x);
            }
            ans += ok;
        }
    }
    cout << ans << '\n';

    return 0;
}