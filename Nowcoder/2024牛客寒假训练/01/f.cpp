#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
constexpr i64 mod = 1e9 + 7;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    auto qmi = [&](int a, int n, i64 mo) {
        i64 res = 1 % mo, t = a;
        while (n) {
            if (n & 1) res = res * t % mo;
            t = t * t % mo;
            n >>= 1;
        }
        return res % mo;
    };
 
    vector<i64> f(m + 11), inf(m + 11);
    f[0] = inf[0] = 1ll;
    for (int i = 1; i <= m + 10; i++) {
        f[i] = f[i - 1] * i % mod;
        inf[i] = inf[i - 1] * qmi(i, mod - 2, mod) % mod;
    }

    auto C = [&](int n, int m) {
        if (m > n) return 0ll;
        return 1ll * f[n] * inf[m] % mod * inf[n - m] % mod;
    };

    i64 ans = 0;
    int sign = 1;
    for (int i = 0; i <= m; i++) {
        ans = (ans + sign * qmi(m - i, n, mod) * C(m, i) + mod) % mod;
        sign = -sign;
    }
    i64 fac = 1;
    for (int i = 1; i <= m; i++) {
        fac = fac * i % mod;
    }
    cout << ans * qmi(fac, mod - 2, mod) % mod << '\n';
    return 0;
}
