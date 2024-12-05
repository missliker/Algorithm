#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
constexpr i64 mod = 998244353;

i64 power(i64 a, i64 n, i64 mo) {
    i64 res = 1 % mo, t = a;
    while (n) {
        if (n & 1) res = res * t % mo;
        t = t * t % mo;
        n >>= 1;
    }
    return res % mo;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 n, m;
    cin >> n >> m;
    i64 x = power(2LL, n, mod);
    i64 ans = power(x, m, mod);
    cout << ans << '\n';

    return 0;
}