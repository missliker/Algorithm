#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
constexpr i64 mod = 1E9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);

    i64 n, seed;
    cin >> n >> seed;

    auto rng = [&]() {
        i64 ret = seed;
        seed = (seed * 7 + 13) % mod;
        return ret % 2;
    };

    vector<int> in(n + 1);
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (rng() == 0) {
                in[j]++;
            } else {
                in[i]++;
            }
        }
    }

    i64 ans = 1LL * n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++) ans -= (in[i] - 1) * in[i] / 2;
    cout << ans << '\n';

    return 0;
}